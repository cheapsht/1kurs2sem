#pragma once
#include <iostream>
#include <string>

namespace graphics {
     /** @brief Абстрактный базовый класс Фигура. */
    class Figure {
    public:
        /** @brief Виртуальный деструктор. */
        virtual ~Figure() = default;
        /**
         * @brief Сериализация объекта в строку.
         * @return Строковое представление фигуры.
         */
        virtual std::string ToString() const = 0;
        /**
         * @brief Чтение объекта из потока ввода.
         * @param is Входной поток.
         */
        virtual void read(std::istream& is) = 0;
    };
}
