#pragma once
#include "figure.h"
#include "point.h"
#include "font.h"
#include <string>
#include <iostream>

namespace graphics {
    /** @brief Класс Текст */
    class Text : public Figure {
    private:
        /** @brief Координата левого нижнего угла */
        Point bottom_left;
         /** @brief Текстовое сообщение */
        std::string message;
        /** @brief Параметры шрифта */
        Font font;
        /** @brief Проверка корректности данных фигуры */
        void validate() const;

    public:
        /** @brief Конструктор по умолчанию */
        Text();
        /**
         * @brief Конструктор с параметрами
         * @param pos Координата левого нижнего угла
         * @param msg Текстовое сообщение
         * @param f Параметры шрифта
         */
        Text(const Point& pos, const std::string& msg, const Font& f);
        /** @brief Сериализация объекта в строку */
        std::string ToString() const override;
        /** @brief Чтение объекта из потока ввода */
        void read(std::istream& is) override;
        /** @brief Установка координаты */
        void setPosition(const Point& pos);
        /** @brief Установка cообщения */
        void setMessage(const std::string& msg);
        /** @brief Установка шрифта */
        void setFont(const Font& f);
        /** @brief Получение координаты */
        const Point& getPosition() const;
        /** @brief Получение сообщения */
        const std::string& getMessage() const;
        /** @brief Получение шрифта */
        const Font& getFont() const;
        /**
         * @brief Статический метод сериализации в строку
         * @param txt Константная ссылка на объект текста
         * @return Строковое представление
         */
        static std::string ToString(const Text& txt);
         /**
         * @brief Статический метод чтения из потока
         * @param is Входной поток
         * @return Объект типа Text
         */
        static Text readFromStream(std::istream& is);
        /**
         * @brief Оператор вывода текста в поток
         * @param os Выходной поток
         * @param txt Константная ссылка на объект текста
         * @return Ссылка на поток
         */
        friend std::ostream& operator<<(std::ostream& os, const Text& txt);
         /**
         * @brief Оператор ввода текста из потока
         * @param is Входной поток
         * @param txt Ссылка на объект текста
         * @return Ссылка на поток
         */
        friend std::istream& operator>>(std::istream& is, Text& txt);
    };
}
