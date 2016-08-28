#include "13_44_47.hpp"
#include <vector>
#include <iostream>

int main() {
    String s1("123"), s2(s1), s3;
    s3 = "123456";
    std::vector<String> vec;
    std::cout << "Push back:" << std::endl;
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);

    return 0;
}