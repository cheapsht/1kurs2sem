#pragma once
#include <iostream>
#include <string>

namespace graphics {
    class Figure {
    public:
        virtual ~Figure() = default;
        virtual std::string ToString() const = 0;
        virtual void read(std::istream& is) = 0;
    };
}

