#include "13_49/String.hpp"
#include <vector>
#include <iostream>

int main() {
    String s1("123"), s2(s1), s3;
    s3 = "123456";
    std::vector<String> vec;
    std::cout << "Push back:" << std::endl;
    vec.push_back(s1);
    std::cout << std::endl;
    vec.push_back(s2);
    std::cout << std::endl;
    vec.push_back(s3);

    return 0;
}