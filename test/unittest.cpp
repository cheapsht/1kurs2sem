#include "../Library/Text.h"
#include "../Library/Point.h"
#include "../Library/Color.h"
#include "../Library/Font.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cmath>
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace graphics;

namespace Tests
{
    TEST_CLASS(PointTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Point p;
            Assert::AreEqual(0.0, p.x);
            Assert::AreEqual(0.0, p.y);
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(TestParameterizedConstructor)
        {
            Point p(3.5, 7.2);
            Assert::AreEqual(3.5, p.x);
            Assert::AreEqual(7.2, p.y);
        }

        // 3. Тест оператора равенства ==
        TEST_METHOD(TestEqualityOperator)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 3.5);
            Point p3(2.5, 4.0);
            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        // 4. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Point p(3.14, 2.71);
            std::stringstream ss;
            ss << p;
            std::string result = ss.str();
            Assert::IsTrue(result.find("(") != std::string::npos);
            Assert::IsTrue(result.find("3.14") != std::string::npos);
        }

        // 5. Тест оператора ввода >>
        TEST_METHOD(TestInputStreamOperator)
        {
            Point p;
            std::string input = "(15.5, 20.3)";
            std::stringstream ss(input);
            ss >> p;
            Assert::AreEqual(15.5, p.x);
            Assert::AreEqual(20.3, p.y);
        }
    };

    TEST_CLASS(ColorTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Color c;
            Assert::AreEqual(0, static_cast<int>(c.getR()));
            Assert::AreEqual(0, static_cast<int>(c.getG()));
            Assert::AreEqual(0, static_cast<int>(c.getB()));
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(TestParameterizedConstructor)
        {
            Color c(10, 20, 30);
            Assert::AreEqual(10, static_cast<int>(c.getR()));
            Assert::AreEqual(20, static_cast<int>(c.getG()));
            Assert::AreEqual(30, static_cast<int>(c.getB()));
        }

        // 3. Тест конструктора с некорректными значениями
        TEST_METHOD(TestConstructorWithInvalidValues)
        {
            auto func = []() {
                Color c(300, 100, 100);
            };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 4. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Color c(255, 128, 64);
            std::stringstream ss;
            ss << c;
            std::string result = ss.str();
            Assert::IsTrue(result.find("255") != std::string::npos);
        }
    };

    TEST_CLASS(FontTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Font f;
            Assert::AreEqual(std::string("Arial"), f.getName());
            Assert::AreEqual(12, f.getSize());
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(TestParameterizedConstructor)
        {
            Color color(255, 0, 0);
            Font f("Verdana", color, 18);
            Assert::AreEqual(std::string("Verdana"), f.getName());
            Assert::AreEqual(18, f.getSize());
        }

        // 3. Тест конструктора с некорректным размером
        TEST_METHOD(TestConstructorWithInvalidSize)
        {
            auto func = []() {
                Color color(0, 0, 0);
                Font f("Arial", color, 0);
            };
            Assert::ExpectException<std::invalid_argument>(func);
        }
    };

    TEST_CLASS(TextTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Text t;
            Assert::IsTrue(true);
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(TestConstructorWithParameters)
        {
            Point pos(10, 20);
            Color color(0, 0, 0);
            Font font("Arial", color, 14);
            Text t(pos, "Hello World", font);
            Assert::AreEqual(10.0, t.getPosition().x);
            Assert::AreEqual(20.0, t.getPosition().y);
            Assert::AreEqual(std::string("Hello World"), t.getMessage());
        }

        // 3. Тест метода ToString()
        TEST_METHOD(TestToString)
        {
            Point pos(0, 0);
            Color color(0, 0, 0);
            Font font("Arial", color, 12);
            Text t(pos, "Test Message", font);
            std::string result = t.ToString();
            Assert::IsTrue(result.find("Text:") != std::string::npos);
            Assert::IsTrue(result.find("Test Message") != std::string::npos);
        }

        // 4. Тест статического метода ToString
        TEST_METHOD(TestStaticToString)
        {
            Point pos(10, 10);
            Color color(0, 0, 0);
            Font font("Arial", color, 14);
            Text t(pos, "Static Test", font);
            std::string result = Text::ToString(t);
            Assert::IsTrue(result.find("Text:") != std::string::npos);
        }

        // 5. Тест метода read()
        TEST_METHOD(TestReadMethod)
        {
            Text t;
            std::string input = "Text: (10,20) | Font: Arial (0,0,0) 14 | Message: \"Read Test\"";
            std::stringstream ss(input);
            t.read(ss);
            Assert::AreEqual(10.0, t.getPosition().x);
            Assert::AreEqual(std::string("Read Test"), t.getMessage());
        }

        // 6. Тест статического метода readFromStream
        TEST_METHOD(TestReadFromStream)
        {
            std::string input = "Text: (5,15) | Font: Verdana (255,0,0) 16 | Message: \"Static Read\"";
            std::stringstream ss(input);
            Text t = Text::readFromStream(ss);
            Assert::AreEqual(5.0, t.getPosition().x);
            Assert::AreEqual(std::string("Static Read"), t.getMessage());
        }

        // 7. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Point pos(0, 0);
            Color color(0, 0, 0);
            Font font("Arial", color, 12);
            Text t(pos, "Output Test", font);
            std::stringstream ss;
            ss << t;
            std::string result = ss.str();
            Assert::IsTrue(result.find("Text:") != std::string::npos);
        }

        // 8. Тест оператора ввода >>
        TEST_METHOD(TestInputStreamOperator)
        {
            Text t;
            std::string input = "Text: (100,200) | Font: Consolas (0,128,255) 18 | Message: \"Input Test\"";
            std::stringstream ss(input);
            ss >> t;
            Assert::AreEqual(100.0, t.getPosition().x);
            Assert::AreEqual(std::string("Input Test"), t.getMessage());
        }

        // 9. Тест полиморфизма через базовый класс
        TEST_METHOD(TestPolymorphism)
        {
            Point pos(0, 0);
            Color color(0, 0, 0);
            Font font("Arial", color, 14);
            std::unique_ptr<Figure> figure = std::make_unique<Text>(pos, "Polymorphism Test", font);
            std::string result = figure->ToString();
            Assert::IsTrue(result.find("Text:") != std::string::npos);
        }

        // 10. Тест коллекции объектов базового класса
        TEST_METHOD(TestCollectionOfFigures)
        {
            std::vector<std::unique_ptr<Figure>> figures;
            
            Point pos1(10, 10);
            Color color1(0, 0, 0);
            Font font1("Arial", color1, 12);
            figures.push_back(std::make_unique<Text>(pos1, "First", font1));
            
            Point pos2(20, 20);
            Color color2(255, 0, 0);
            Font font2("Verdana", color2, 14);
            figures.push_back(std::make_unique<Text>(pos2, "Second", font2));
            
            Assert::AreEqual(size_t(2), figures.size());
            Assert::IsTrue(figures[0]->ToString().find("First") != std::string::npos);
            Assert::IsTrue(figures[1]->ToString().find("Second") != std::string::npos);
        }
    };
}
