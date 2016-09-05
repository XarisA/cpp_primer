#include "15_3.hpp"
#include <iostream>

std::ostream& print_total(std::ostream &os, const Quote &q, const std::size_t n) {
    os << "ISBN: " << q.isbn()
    << "\nNumber of items: " << n
    << "\nTotal: " << q.net_price(n);
    return os;
}

int main() {
    Quote q("101-12345-999", 13.99);
    print_total(std::cout, q, 15) << std::endl;
    return 0;
}