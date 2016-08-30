#include "14_6_9.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream &os, const Sales_data &s) {
    os << s.bookNo << ' ' << s.units_sold << ' ' << s.revenue;
    return os;
}

int main() {
    Sales_data s;
    std::cout << s << std::endl;
    return 0;
}