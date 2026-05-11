#include <sstream>
#include <stdexcept>

namespace graphics {
    Text::Text() : bottom_left(0.0, 0.0), message(""), font() {}

    Text::Text(const Point& pos, const std::string& msg, const Font& f)
        : bottom_left(pos), message(msg), font(f) {
        validate();
    }

    void Text::validate() const {
        if (font.getSize() <= 0) throw std::invalid_argument("Некорректный размер шрифта");
    }

    std::string Text::ToString() const {
        std::stringstream ss;
        ss << "Text: " << bottom_left << " | Font: " << font << " | Message: \"" << message << "\"";
        return ss.str();
    }

    void Text::read(std::istream& is) {
        std::string keyword, pipe;
        is >> keyword; 
        is >> bottom_left; 
        is >> pipe; 
        is >> keyword; 
        is >> font; 
        is >> pipe; \
        is >> keyword;
        is >> std::ws;
        char quote;
        is >> quote; 
        std::getline(is, message, '"'); 
        validate();
    }

    void Text::setPosition(const Point& pos) { bottom_left = pos; }
    void Text::setMessage(const std::string& msg) { message = msg; }
    void Text::setFont(const Font& f) { font = f; validate(); }

    const Point& Text::getPosition() const { return bottom_left; }
    const std::string& Text::getMessage() const { return message; }
    const Font& Text::getFont() const { return font; }

    std::string Text::ToString(const Text& txt) { return txt.ToString(); }
    Text Text::readFromStream(std::istream& is) {
        Text txt;
        txt.read(is);
        return txt;
    }

    std::ostream& operator<<(std::ostream& os, const Text& txt) {
        os << txt.ToString();
        return os;
    }

    std::istream& operator>>(std::istream& is, Text& txt) {
        txt.read(is);
        return is;
    }
}
