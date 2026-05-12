#include "../include/Vector.h"
#include "CppUnitTest.h"
#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace containers;

namespace Tests {

    TEST_CLASS(VectorConstructorTests) {
    public:

        /**
         * @brief Тест конструктора по умолчанию
         */
        TEST_METHOD(TestDefaultConstructor) {
            Vector v;
            Assert::IsTrue(v.isEmpty(), L"Вектор должен быть пустым после конструктора по умолчанию");
            Assert::AreEqual(size_t(0), v.getSize(), L"Размер должен быть 0");
            Assert::AreEqual(std::string("[]"), v.ToString(), L"Строковое представление должно быть []");
        }

        /**
         * @brief Тест конструктора со списком инициализации
         */
        TEST_METHOD(TestInitializerListConstructor) {
            Vector v{ 1, 2, 3, 4, 5 };
            Assert::IsFalse(v.isEmpty(), L"Вектор не должен быть пустым");
            Assert::AreEqual(size_t(5), v.getSize(), L"Размер должен быть 5");
            Assert::AreEqual(1, v[0], L"Первый элемент должен быть 1");
            Assert::AreEqual(3, v[2], L"Третий элемент должен быть 3");
            Assert::AreEqual(5, v[4], L"Пятый элемент должен быть 5");
            Assert::AreEqual(std::string("[1, 2, 3, 4, 5]"), v.ToString(), L"Неверное строковое представление");
        }

        /**
         * @brief Тест конструктора со списком инициализации (пустой список)
         */
        TEST_METHOD(TestInitializerListConstructorEmpty) {
            Vector v{};
            Assert::IsTrue(v.isEmpty(), L"Вектор должен быть пустым");
            Assert::AreEqual(size_t(0), v.getSize(), L"Размер должен быть 0");
        }

        /**
         * @brief Тест конструктора со списком инициализации (один элемент)
         */
        TEST_METHOD(TestInitializerListConstructorSingle) {
            Vector v{ 42 };
            Assert::AreEqual(size_t(1), v.getSize(), L"Размер должен быть 1");
            Assert::AreEqual(42, v[0], L"Единственный элемент должен быть 42");
        }

        /**
         * @brief Тест конструктора копирования
         */
        TEST_METHOD(TestCopyConstructor) {
            Vector original{ 10, 20, 30 };
            Vector copy(original);
            
            Assert::AreEqual(original.getSize(), copy.getSize(), L"Размеры должны совпадать");
            Assert::AreEqual(original.ToString(), copy.ToString(), L"Содержимое должно совпадать");
            
            // Проверка независимости объектов
            copy.pushBack(40);
            Assert::AreEqual(size_t(3), original.getSize(), L"Оригинал не должен измениться");
            Assert::AreEqual(size_t(4), copy.getSize(), L"Копия должна измениться");
        }

        /**
         * @brief Тест конструктора копирования (пустой вектор)
         */
        TEST_METHOD(TestCopyConstructorEmpty) {
            Vector original;
            Vector copy(original);
            
            Assert::IsTrue(copy.isEmpty(), L"Копия пустого вектора должна быть пустой");
            Assert::AreEqual(size_t(0), copy.getSize(), L"Размер копии должен быть 0");
        }

        /**
         * @brief Тест конструктора перемещения
         */
        TEST_METHOD(TestMoveConstructor) {
            Vector original{ 100, 200, 300 };
            std::string originalStr = original.ToString();
            
            Vector moved(std::move(original));
            
            Assert::IsTrue(original.isEmpty(), L"Исходный вектор должен быть пуст после move");
            Assert::AreEqual(size_t(3), moved.getSize(), L"Перемещённый вектор должен содержать 3 элемента");
            Assert::AreEqual(100, moved[0], L"Первый элемент должен быть 100");
            Assert::AreEqual(300, moved[2], L"Третий элемент должен быть 300");
            Assert::AreEqual(originalStr, moved.ToString(), L"Содержимое должно сохраниться");
        }

        /**
         * @brief Тест конструктора перемещения (пустой вектор)
         */
        TEST_METHOD(TestMoveConstructorEmpty) {
            Vector original;
            Vector moved(std::move(original));
            
            Assert::IsTrue(moved.isEmpty(), L"Перемещённый пустой вектор должен остаться пустым");
            Assert::IsTrue(original.isEmpty(), L"Исходный вектор должен остаться пустым");
        }
    };

    TEST_CLASS(VectorOperatorTests) {
    public:

        /**
         * @brief Тест оператора присваивания (копирование)
         */
        TEST_METHOD(TestCopyAssignmentOperator) {
            Vector v1{ 1, 2, 3 };
            Vector v2;
            v2 = v1;
            
            Assert::AreEqual(v1.ToString(), v2.ToString(), L"Содержимое должно совпадать после присваивания");
            
            // Проверка независимости
            v2.pushBack(4);
            Assert::AreEqual(size_t(3), v1.getSize(), L"Оригинал не должен измениться");
            Assert::AreEqual(size_t(4), v2.getSize(), L"Копия должна измениться");
        }

        /**
         * @brief Тест оператора присваивания (сам присваивает себе)
         */
        TEST_METHOD(TestSelfAssignment) {
            Vector v{ 10, 20, 30 };
            v = v;
            
            Assert::AreEqual(size_t(3), v.getSize(), L"Размер не должен измениться");
            Assert::AreEqual(10, v[0], L"Элементы должны сохраниться");
            Assert::AreEqual(30, v[2], L"Элементы должны сохраниться");
        }

        /**
         * @brief Тест оператора присваивания (перемещение)
         */
        TEST_METHOD(TestMoveAssignmentOperator) {
            Vector v1{ 5, 10, 15 };
            Vector v2{ 1, 2, 3, 4 };
            
            v2 = std::move(v1);
            
            Assert::IsTrue(v1.isEmpty(), L"Исходный вектор должен быть пуст");
            Assert::AreEqual(size_t(3), v2.getSize(), L"Целевой вектор должен содержать 3 элемента");
            Assert::AreEqual(5, v2[0], L"Первый элемент должен быть 5");
        }

        /**
         * @brief Тест оператора индексации (чтение)
         */
        TEST_METHOD(TestIndexOperatorRead) {
            Vector v{ 10, 20, 30, 40 };
            Assert::AreEqual(10, v[0]);
            Assert::AreEqual(20, v[1]);
            Assert::AreEqual(30, v[2]);
            Assert::AreEqual(40, v[3]);
        }

        /**
         * @brief Тест оператора индексации (запись)
         */
        TEST_METHOD(TestIndexOperatorWrite) {
            Vector v{ 1, 2, 3 };
            v[1] = 99;
            Assert::AreEqual(99, v[1], L"Значение должно измениться");
            Assert::AreEqual(std::string("[1, 99, 3]"), v.ToString(), L"Строковое представление должно обновиться");
        }

        /**
         * @brief Тест оператора индексации (выход за границы - чтение)
         */
        TEST_METHOD(TestIndexOperatorOutOfRangeRead) {
            Vector v{ 1, 2, 3 };
            auto func = [&v]() { volatile int x = v[10]; };
            Assert::ExpectException<std::out_of_range>(func, L"Должно быть выброшено исключение при чтении за границами");
        }

        /**
         * @brief Тест оператора индексации (выход за границы - запись)
         */
        TEST_METHOD(TestIndexOperatorOutOfRangeWrite) {
            Vector v{ 1, 2, 3 };
            auto func = [&v]() { v[10] = 42; };
            Assert::ExpectException<std::out_of_range>(func, L"Должно быть выброшено исключение при записи за границами");
        }

        /**
         * @brief Тест оператора вывода в поток
         */
        TEST_METHOD(TestOutputStreamOperator) {
            Vector v{ 7, 14, 21 };
            std::ostringstream oss;
            oss << v;
            Assert::AreEqual(std::string("[7, 14, 21]"), oss.str(), L"Вывод в поток должен совпадать с ToString()");
        }

        /**
         * @brief Тест оператора ввода из потока
         */
        TEST_METHOD(TestInputStreamOperator) {
            Vector v;
            std::istringstream iss("[5, 10, 15]");
            iss >> v;
            
            Assert::AreEqual(size_t(3), v.getSize(), L"Размер должен быть 3");
            Assert::AreEqual(5, v[0]);
            Assert::AreEqual(10, v[1]);
            Assert::AreEqual(15, v[2]);
        }
    };

    TEST_CLASS(VectorMethodTests) {
    public:

        /**
         * @brief Тест метода pushBack
         */
        TEST_METHOD(TestPushBack) {
            Vector v;
            v.pushBack(1);
            v.pushBack(2);
            v.pushBack(3);
            
            Assert::AreEqual(size_t(3), v.getSize());
            Assert::AreEqual(1, v[0]);
            Assert::AreEqual(2, v[1]);
            Assert::AreEqual(3, v[2]);
        }

        /**
         * @brief Тест метода pushBack с автоматическим расширением
         */
        TEST_METHOD(TestPushBackResize) {
            Vector v;
            for (int i = 0; i < 100; ++i) {
                v.pushBack(i);
            }
            Assert::AreEqual(size_t(100), v.getSize());
            Assert::AreEqual(0, v[0]);
            Assert::AreEqual(99, v[99]);
        }

        /**
         * @brief Тест метода removeAt
         */
        TEST_METHOD(TestRemoveAt) {
            Vector v{ 10, 20, 30, 40 };
            Assert::IsTrue(v.removeAt(1), L"Удаление по валидному индексу должно вернуть true");
            Assert::AreEqual(size_t(3), v.getSize());
            Assert::AreEqual(10, v[0]);
            Assert::AreEqual(30, v[1]);
            Assert::AreEqual(40, v[2]);
        }

        /**
         * @brief Тест метода removeAt (невалидный индекс)
         */
        TEST_METHOD(TestRemoveAtInvalid) {
            Vector v{ 1, 2, 3 };
            Assert::IsFalse(v.removeAt(10), L"Удаление по невалидному индексу должно вернуть false");
            Assert::AreEqual(size_t(3), v.getSize(), L"Размер не должен измениться");
        }

        /**
         * @brief Тест метода remove (по значению)
         */
        TEST_METHOD(TestRemoveByValue) {
            Vector v{ 1, 2, 3, 2, 4 };
            Assert::IsTrue(v.remove(2), L"Удаление существующего значения должно вернуть true");
            Assert::AreEqual(size_t(4), v.getSize());
            Assert::AreEqual(-1, v.indexOf(2), L"Первое вхождение должно быть удалено");
        }

        /**
         * @brief Тест метода remove (значение не найдено)
         */
        TEST_METHOD(TestRemoveByValueNotFound) {
            Vector v{ 1, 2, 3 };
            Assert::IsFalse(v.remove(99), L"Удаление несуществующего значения должно вернуть false");
            Assert::AreEqual(size_t(3), v.getSize());
        }

        /**
         * @brief Тест метода indexOf
         */
        TEST_METHOD(TestIndexOf) {
            Vector v{ 10, 20, 30, 40 };
            Assert::AreEqual(0, v.indexOf(10));
            Assert::AreEqual(2, v.indexOf(30));
            Assert::AreEqual(-1, v.indexOf(99), L"Ненайденный элемент должен вернуть -1");
        }

        /**
         * @brief Тест метода isEmpty
         */
        TEST_METHOD(TestIsEmpty) {
            Vector v;
            Assert::IsTrue(v.isEmpty());
            v.pushBack(1);
            Assert::IsFalse(v.isEmpty());
            v.clear();
            Assert::IsTrue(v.isEmpty());
        }

        /**
         * @brief Тест метода getSize
         */
        TEST_METHOD(TestGetSize) {
            Vector v;
            Assert::AreEqual(size_t(0), v.getSize());
            v.pushBack(1);
            v.pushBack(2);
            Assert::AreEqual(size_t(2), v.getSize());
        }

        /**
         * @brief Тест метода ToString
         */
        TEST_METHOD(TestToString) {
            Vector empty;
            Assert::AreEqual(std::string("[]"), empty.ToString());
            
            Vector single{ 42 };
            Assert::AreEqual(std::string("[42]"), single.ToString());
            
            Vector multi{ 1, 2, 3 };
            Assert::AreEqual(std::string("[1, 2, 3]"), multi.ToString());
        }

        /**
         * @brief Тест метода clear
         */
        TEST_METHOD(TestClear) {
            Vector v{ 1, 2, 3, 4, 5 };
            v.clear();
            Assert::IsTrue(v.isEmpty());
            Assert::AreEqual(size_t(0), v.getSize());
            Assert::AreEqual(std::string("[]"), v.ToString());
        }
    };

} // namespace Tests
