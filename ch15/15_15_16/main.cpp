#include "Limited_quote.hpp"
#include "Bulk_quote.hpp"
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

    Bulk_quote b("101-12333-888", 17.99, 15, 0.8);
    print_total(std::cout, b, 3) << std::endl;
    print_total(std::cout, b, 60) << std::endl;

    Limited_quote l("101-12333-888", 17.99, 15, 0.8);
    print_total(std::cout, l, 15) << std::endl;
    print_total(std::cout, l, 16) << std::endl;
    return 0;
}