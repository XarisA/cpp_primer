#include "14_6_9.hpp"
#include <iostream>

std::istream& operator>>(std::istream &is, Sales_data &s) {
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    if (is) {
        s.revenue = s.units_sold * price;
    }
    else {
        s = Sales_data();
    }
    return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &s) {
    os << s.bookNo << ' ' << s.units_sold << ' ' << s.revenue;
    return os;
}

int main() {
    Sales_data s;
    std::cin >> s;
    std::cout << s;
    return 0;
}