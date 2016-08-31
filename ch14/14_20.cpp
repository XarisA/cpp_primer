#include "14_6_9.hpp"

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &s1, const Sales_data &s2) {
    Sales_data result = s1;
    result += s2;
    return result;
}

int main() {
    
}