#include <iostream>
#include "Vec.hpp"

int main() {
    Vec<std::string> vec;
    std::string s1("this is a test");
    vec.push_back(s1);
    std::cout << vec[0] << std::endl;
    return 0;
}