#pragma once
#include <initializer_list>
#include <string>
#include <cstddef>
#include <iosfwd>

namespace containers {

/**
 * @brief Класс Вектор — динамический массив целых чисел.
 * Реализует вставку, удаление, поиск, доступ по индексу.
 */
class Vector {
private:
    int* data_;
    size_t size_;
    size_t capacity_;

    /**
     * @brief Выделяет новую память и копирует данные
     * @param newCapacity новая ёмкость
     */
    void reserve(const size_t newCapacity);

    /**
     * @brief Копирует данные из другого вектора
     * @param other вектор для копирования
     */
    void copyFrom(const Vector& other);

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector();

    /**
     * @brief Конструктор со списком инициализации
     * @param init список инициализации
     */
    Vector(const std::initializer_list<int> init);

    /**
     * @brief Конструктор копирования
     * @param other другой вектор
     */
    Vector(const Vector& other);

    /**
     * @brief Конструктор перемещения
     * @param other другой вектор
     */
    Vector(Vector&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~Vector();

    /**
     * @brief Оператор присваивания (копирование)
     * @param other другой вектор
     * @return ссылка на текущий объект
     */
    Vector& operator=(const Vector& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other другой вектор
     * @return ссылка на текущий объект
     */
    Vector& operator=(Vector&& other) noexcept;

    /**
     * @brief Доступ по индексу (неконстантный)
     * @param index индекс элемента
     * @return ссылка на элемент
     */
    int& operator[](const size_t index);

    /**
     * @brief Доступ по индексу (константный)
     * @param index индекс элемента
     * @return константная ссылка на элемент
     */
    const int& operator[](size_t index) const;

    /**
     * @brief Добавление элемента в конец
     * @param value значение элемента
     */
    void pushBack(const int value);

    /**
     * @brief Удаление элемента по индексу
     * @param index позиция элемента
     * @return true, если элемент удалён
     */
    bool removeAt(const size_t index);

    /**
     * @brief Удаление первого вхождения значения
     * @param value значение для удаления
     * @return true, если элемент найден и удалён
     */
    bool remove(const int value);

    /**
     * @brief Поиск элемента по значению
     * @param value значение для поиска
     * @return индекс элемента или -1, если не найден
     */
    int indexOf(const int value) const;

    /**
     * @brief Проверка, пуст ли вектор
     * @return true, если вектор пуст
     */
    bool isEmpty() const;

    /**
     * @brief Получение размера вектора
     * @return количество элементов
     */
    size_t getSize() const;

    /**
     * @brief Сериализация в строку
     * @return строковое представление вектора
     */
    std::string ToString() const;

    /**
     * @brief Очистка вектора
     */
    void clear();
};

/**
 * @brief Оператор вывода в поток
 * @param os выходной поток
 * @param vec вектор для вывода
 * @return ссылка на поток
 */
std::ostream& operator<<(std::ostream& os, const Vector& vec);

/**
 * @brief Оператор ввода из потока
 * @param is входной поток
 * @param vec вектор для заполнения
 * @return ссылка на поток
 */
std::istream& operator>>(std::istream& is, Vector& vec);

}
