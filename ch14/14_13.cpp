#include "14_6_9.hpp"
#include <iostream>

Sales_data operator+(const Sales_data &s1, const Sales_data &s2) {
    Sales_data result = s1;
    result += s2;
    return result;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


int main() {
    Sales_data s1("101", 105, 3.7), s2("101", 15, 7.2);
    print(std::cout, s1 + s2) << std::endl;
    s1 += s2;
    print(std::cout, s1) << std::endl;
    return 0;
}