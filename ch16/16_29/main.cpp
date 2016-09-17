#include "Blob.hpp"
#include <iostream>

int main() {
    Blob<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    
    std::cout << a[1] << std::endl;
    
    return 0;
}