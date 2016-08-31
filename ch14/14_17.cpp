#include "14_5_8_12.hpp"
#include <iostream>

bool operator==(const Book &b1, const Book &b2) {
    return b1.name == b2.name && b1.price == b2.price;
}

bool operator!=(const Book &b1, const Book &b2) {
    return !(b1==b2);
}

int main() {
    Book b1("Book1", 10), b2("Book1", 10), b3("Book2", 11);
    std::cout << (b1 == b2) << std::endl;
    std::cout << (b2 != b3) << std::endl;
    return 0;
}