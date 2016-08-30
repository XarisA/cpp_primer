#include "14_5_8_12.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Book &b) {
    os << b.name << ' ' << b.price;
    return os;
}

std::istream &operator>>(std::istream &is, Book &b) {
    is >> b.name >> b.price;
    if (!is) b = Book();
    return is;
}

int main() {
    Book b;
    std::cin >> b;
    std::cout << b << std::endl;
    return 0;
}