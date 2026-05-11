#include "../include/Vector.h"
#include <iostream>
#include <sstream>

using namespace containers;

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена успешно
 */
int main() {
    std::cout << "Демонстрация работы с вектором \n\n";

    std::cout << "1. Конструктор со списком инициализации:\n";
    Vector vec1{ 10, 20, 30, 40, 50 };
    std::cout << "vec1: " << vec1 << "\n";
    std::cout << "Размер: " << vec1.getSize() << "\n";
    std::cout << "Пустой? " << (vec1.isEmpty() ? "да" : "нет") << "\n\n";

    std::cout << "2. Конструктор копирования:\n";
    Vector vec2(vec1);
    std::cout << "vec2 (копия vec1): " << vec2 << "\n\n";

    std::cout << "3. Оператор присваивания:\n";
    Vector vec3;
    vec3 = vec1;
    std::cout << "vec3 (присвоен vec1): " << vec3 << "\n\n";

    std::cout << "4. Вставка элементов:\n";
    vec1.pushBack(60);
    std::cout << "После pushBack(60): " << vec1 << "\n";
    vec1.pushBack(70);
    std::cout << "После pushBack(70): " << vec1 << "\n\n";

    std::cout << "5. Доступ по индексу:\n";
    std::cout << "vec1[2] = " << vec1[2] << "\n";
    vec1[2] = 35;
    std::cout << "После vec1[2] = 35: " << vec1 << "\n\n";

    std::cout << "6. Поиск элемента:\n";
    std::cout << "vec1: " << vec1 << "\n";
    int searchValue = 35;
    int idx = vec1.indexOf(searchValue);
    if (idx != -1) {
        std::cout << "Элемент " << searchValue << " найден на позиции " << idx << "\n";
    } else {
        std::cout << "Элемент " << searchValue << " не найден\n";
    }
    searchValue = 100;
    idx = vec1.indexOf(searchValue);
    if (idx != -1) {
        std::cout << "Элемент " << searchValue << " найден на позиции " << idx << "\n";
    } else {
        std::cout << "Элемент " << searchValue << " не найден\n";
    }
    std::cout << "\n";

    std::cout << "7. Удаление элементов:\n";
    vec1.remove(20);
    std::cout << "После remove(20): " << vec1 << "\n";
    vec1.removeAt(0);
    std::cout << "После removeAt(0): " << vec1 << "\n\n";

    std::cout << "8. Итерация по элементам:\n";
    std::cout << "Элементы вектора: ";
    for (size_t i = 0; i < vec1.getSize(); ++i) {
        std::cout << vec1[i];
        if (i < vec1.getSize() - 1) std::cout << ", ";
    }
    std::cout << "\n\n";

    std::cout << "9. Работа с пустым вектором:\n";
    Vector emptyVec;
    std::cout << "Пустой вектор: " << emptyVec << "\n";
    std::cout << "Размер: " << emptyVec.getSize() << "\n";
    std::cout << "Пустой? " << (emptyVec.isEmpty() ? "да" : "нет") << "\n";
    emptyVec.pushBack(42);
    std::cout << "После pushBack(42): " << emptyVec << "\n\n";

    std::cout << "10. Очистка вектора:\n";
    std::cout << "До очистки: " << vec2 << "\n";
    vec2.clear();
    std::cout << "После clear(): " << vec2 << "\n";
    std::cout << "Размер: " << vec2.getSize() << "\n\n";

    std::cout << "11. Проверка на исключения:\n";
    Vector testVec;
    try {
        std::cout << "Попытка получить элемент из пустого вектора: ";
        testVec[0];
    } catch (const std::out_of_range& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    try {
        std::cout << "Попытка удалить по неверному индексу: ";
        testVec.removeAt(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    std::cout << "\nПрограмма завершена успешно.\n";
    return 0;
}
