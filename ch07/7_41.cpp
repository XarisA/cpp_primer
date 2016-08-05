#include "7_41.hpp"

int main() {
    Sales_data s1;
    std::cout << std::endl;

    Sales_data s2("ISBN12345");
    std::cout << std::endl;

    Sales_data s3("ISBN66666", 15, 25.4);
    std::cout << std::endl;
    
    Sales_data s4(std::cin);
    return 0;
}