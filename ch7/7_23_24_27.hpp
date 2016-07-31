#ifndef SCREENS_OBJ
#define SCREENS_OBJ

#include <string>
#include <iostream>

class Screen {
    public:
        using pos = std::string::size_type;
        Screen() = default;
        Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {};
        Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {};

        inline char get() const {
            return contents[cursor];
        }
        inline char get(pos h, pos w) const;
        inline Screen &move(pos r, pos c);
        inline Screen &set(pos, pos, char);
        inline Screen &set(char);

        Screen &display(std::ostream &os) {
            do_display(os);
            return *this;
        }

        const Screen &display(std::ostream &os) const {
            do_display(os);
            return *this;
        }
        
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
        void do_display(std::ostream &os) const {
            os << contents;
        }
};

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

#endif