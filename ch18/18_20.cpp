#include <iostream>

namespace primerLib {
    void compute() { std::cout << "conpute()" << std::endl; }
    void compute(const void*) { 
        std::cout << "conpute(const void *)" << std::endl; 
    }
}

using primerLib::compute;   // calls compute()

void compute(int) { std::cout << "conpute(int)" << std::endl; }
void compute(double, double = 3.4) {
    std::cout << "conpute(double, double = 3.4)" << std::endl;
}
void compute(char*) { 
    std::cout << "conpute(char*)" << std::endl;
}

int main() {
    // using primerLib::compute;    // calls onpute(const void *)
    compute(0);
    return 0;
}