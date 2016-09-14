#include "Screen.hpp"

template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

template <unsigned H, unsigned W>
char Screen<H, W>::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}

template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::set(char c) {
    contents[cursor] = c;
    return *this;
}
