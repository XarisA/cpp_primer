#include "../ch13/13_44_47.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream &os, const String &s) {
    auto p = s.cStringBegin;
    while (p != s.cStringEnd) {
        os << *p++;
    }
    return os;
}

int main() {
    String str("this is a test");
    std::cout << str << std::endl;
    return 0;
}