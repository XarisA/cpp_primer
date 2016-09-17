#include <iostream>

int main() {
    double a = 20.2;
    int b = 3;
    //std::cout << std::max(a, b) << std::endl;
    std::cout << std::max<int>(a, b) << std::endl;
    std::cout << std::max<double>(a, b) << std::endl;

    return 0;
}