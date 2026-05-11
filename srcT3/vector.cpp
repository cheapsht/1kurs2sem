#include "../include/Vector.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

namespace containers {

void Vector::reserve(size_t newCapacity) {
    if (newCapacity <= capacity_) return;
    int* newData = new int[newCapacity];
    if (data_ && size_ > 0) {
        std::copy(data_, data_ + size_, newData);
    }
    delete[] data_;
    data_ = newData;
    capacity_ = newCapacity;
}

void Vector::copyFrom(const Vector& other) {
    if (other.size_ > 0) {
        data_ = new int[other.capacity_];
        std::copy(other.data_, other.data_ + other.size_, data_);
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
}

Vector::Vector() 
    : data_(nullptr), size_(0), capacity_(0) {}

Vector::Vector(std::initializer_list<int> init) 
    : data_(nullptr), size_(0), capacity_(init.size()) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        std::copy(init.begin(), init.end(), data_);
        size_ = init.size();
    }
}

Vector::Vector(const Vector& other) 
    : data_(nullptr), size_(0), capacity_(0) {
    copyFrom(other);
}

Vector::Vector(Vector&& other) noexcept 
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

Vector::~Vector() {
    delete[] data_;
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

int& Vector::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Индекс выходит за пределы вектора");
    }
    return data_[index];
}

const int& Vector::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Индекс выходит за пределы вектора");
    }
    return data_[index];
}

void Vector::pushBack(int value) {
    if (size_ >= capacity_) {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
}

bool Vector::removeAt(size_t index) {
    if (index >= size_) return false;
    for (size_t i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }
    --size_;
    return true;
}

bool Vector::remove(int value) {
    int idx = indexOf(value);
    return (idx == -1) ? false : removeAt(static_cast<size_t>(idx));
}

int Vector::indexOf(int value) const {
    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] == value) return static_cast<int>(i);
    }
    return -1;
}

bool Vector::isEmpty() const { return size_ == 0; }
size_t Vector::getSize() const { return size_; }

std::string Vector::ToString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < size_; ++i) {
        oss << data_[i];
        if (i < size_ - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

void Vector::clear() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    return os << vec.ToString();
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    vec.clear();
    char ch;
    int value;
    if (is >> ch && ch != '[') is.putback(ch);
    while (is >> value) {
        vec.pushBack(value);
        if (is.peek() == ']' || is.peek() == ',') {
            is.get(ch);
            if (ch == ']') break;
        }
    }
    return is;
}

}
