#include <iostream>

namespace primerLib {
    void compute() { std::cout << "compute()" << std::endl; }
    void compute(const void*) { 
        std::cout << "compute(const void *)" << std::endl; 
    }
}

using primerLib::compute;   // calls compute()

void compute(int) { std::cout << "compute(int)" << std::endl; }
void compute(double, double = 3.4) {
    std::cout << "compute(double, double = 3.4)" << std::endl;
}
void compute(char*) { 
    std::cout << "compute(char*)" << std::endl;
}

int main() {
    // using primerLib::compute;    // calls onpute(const void *)
    compute(0);
    return 0;
}