#include "font.h"
#include <sstream>

namespace graphics {

Font::Font(const std::string& name, const Color& color, const int size)
    : name(name), color(color), size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Font size must be positive");
    }
}

const std::string& Font::getName() const { return name; }
const Color& Font::getColor() const { return color; }
int Font::getSize() const { return size; }

void Font::setName(const std::string& newName) { name = newName; }

void Font::setColor(const Color& newColor) { color = newColor; }

void Font::setSize(const int newSize) {
    if (newSize <= 0) {
        throw std::invalid_argument("Font size must be positive");
    }
    size = newSize;
}

std::ostream& operator<<(std::ostream& os, const Font& f) {
    os << f.name << " " << f.color << " " << f.size;
    return os;
}

std::istream& operator>>(std::istream& is, Font& f) {
    std::string name;
    Color color;
    int size;

    is >> name;
    is >> color;
    is >> size;
    if (size <= 0) {
        throw std::invalid_argument("Font size must be positive");
    }
    f = Font(name, color, size);
    return is;
}

} 
