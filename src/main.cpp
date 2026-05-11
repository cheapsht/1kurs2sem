#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include "Text.h"
/**
* @brief точка входа в программу
* @return 0, если программа выполнена успешно
*/
int main() {
    try {
        std::vector<std::unique_ptr<graphics::Figure>> figures;

        graphics::Text t1(graphics::Point(10, 10), "Hello World!",
                          graphics::Font("Arial", graphics::Color(0, 0, 0), 14));
        graphics::Text t2(graphics::Point(50, 50), "GOST Compliant",
                          graphics::Font("Times New Roman", graphics::Color(255, 0, 0), 12));

        figures.push_back(std::make_unique<graphics::Text>(t1));
        figures.push_back(std::make_unique<graphics::Text>(t2));

        std::cout << " Вывод коллекции фигур \n";
        for (const auto& fig : figures) {
            std::cout << fig->ToString() << "\n";
        }

        std::cout << "\n Статический ToString \n";
        std::cout << graphics::Text::ToString(t1) << "\n";

        std::cout << "\n Чтение из строки \n";
        std::string input = "Text: (100,200) | Font: Consolas (0,128,255) 16 | Message: \"Code Review\"";
        std::stringstream ss(input);
        graphics::Text t3 = graphics::Text::readFromStream(ss);
        std::cout << t3 << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
