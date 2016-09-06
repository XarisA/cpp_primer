#include "15_5.hpp"
#include <iostream>

int main() {
    Quote q("101-12345-999", 13.99);
    q.debug();
    std::cout << std::endl;

    Bulk_quote b("101-12333-888", 17.99, 15, 0.8);
    b.debug();
    std::cout << std::endl;

    Quote *p = &b;
    p->debug();
    std::cout << std::endl;
    
    p->Quote::debug();
    std::cout << std::endl;

    return 0;
} 