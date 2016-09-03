#include "14_6_9.hpp"
#include <iostream>

int main() {
    Sales_data s1("101-9999-002", 23, 7.99);
    std::cout << static_cast<std::string>(s1) << ' ' << static_cast<double>(s1) << std::endl;
    return 0;
}