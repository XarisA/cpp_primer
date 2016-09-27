#include <iostream>
#include <cstdlib>
#include "../../ch13/13_39_40_43.hpp"

void *operator new(size_t size) {
    std::cout << "our version of operator new is called" << std::endl;
    if (void *mem = malloc(size))   
        return mem;
    else
        throw std::bad_alloc();
}

void operator delete(void *mem) noexcept { 
    free(mem);
    std::cout << "our version of operator delete is called" << std::endl;
}

int main() {
    StrVec *vp = new StrVec();
    delete vp;
    return 0;
}