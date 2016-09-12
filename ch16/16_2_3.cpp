#include <iostream>
#include <functional>
#include "../ch14/14_6_9.hpp"

template <typename T> int compare(const T &a, const T &b) {
    if(std::less<T>()(a, b)) return -1;
    if(std::less<T>()(b, a)) return 1;
    return 0;
} 

int main() {
    int a = 3, b = 6;
    double d1 = 5.5, d2 = 3.3;
    std::string s1("a"), s2("b");
    std::cout << compare(a, b) << "\n"
                << compare(d1, d2) << "\n"
                << compare(s1, s2) << std::endl;
    
    /*
    Sales_data sd1("123", 10, 10), sd2("456", 8, 8);
    std::cout << compare(sd1, sd2) << std::endl;

    error: invalid operands to binary expression ('const Sales_data' and 'const Sales_data')
        {return __x < __y;}
    */
    return 0;
}