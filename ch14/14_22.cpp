#include "14_6_9.hpp"
#include <iostream>

Sales_data& Sales_data::operator=(const string &isbn) {
    bookNo = isbn;
    return *this;
}

int main() {
    Sales_data s("Old", 1, 1);
    print(std::cout, s) << std::endl;
    s = "new";
    print(std::cout, s) << std::endl;
    return 0;
}