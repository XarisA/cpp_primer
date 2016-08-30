#include "14_5_8_12.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Book &b) {
    os << b.name << ' ' << b.price;
    return os;
}

int main() {
    Book b("CPP Primer", 69.99);
    std::cout << b << std::endl;
    return 0;
}