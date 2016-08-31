#include "14_6_9.hpp"
#include <iostream>

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    *this = *this + rhs;        // this will make a copy of *this
    return *this;
}

Sales_data operator+(const Sales_data &s1, const Sales_data &s2) {
    Sales_data result;
    result.units_sold = s1.units_sold + s2.units_sold;
    result.revenue = s1.revenue + s2.revenue;
    result.bookNo = s1.bookNo;
    return result;
}

int main() {
    Sales_data s1("001", 10, 10), s2("001", 10, 15);
    s1 += s2;
    print(std::cout, s1) << std::endl;
    return 0;
}