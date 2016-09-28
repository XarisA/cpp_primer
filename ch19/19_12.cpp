#include "../ch07/7_32.hpp"     // Screen header
#include <iostream>

int main() {
    Screen s1(3, 3, 'x');
    s1.move(2, 2);
    const Screen::pos Screen::*pc = Screen::pCursor();
    std::cout << s1.*pc << std::endl;
    return 0;
}