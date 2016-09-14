#ifndef SCREEN
#define SCREEN

#include <string>
#include <iostream>

template <unsigned H, unsigned W> class Screen;

template <unsigned H, unsigned W> 
std::ostream& operator<<(std::ostream&, const Screen<H, W>&);

template <unsigned H, unsigned W>
std::istream& operator>>(std::istream&, Screen<H, W>&);

template <unsigned H, unsigned W>
class Screen {
    friend std::ostream& operator<< <H, W>(std::ostream&, const Screen<H, W>&);
    friend std::istream& operator>> <H, W>(std::istream&, const Screen<H, W>&);
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(char c) : contents(H * W, c) { };

    inline char get() const { return contents[cursor]; }
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
    pos height = H, width = W;
    std::string contents;
    void do_display(std::ostream &os) const {
        os << contents;
    }
};

#endif