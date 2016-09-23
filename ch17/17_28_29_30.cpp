#include <random>
#include <iostream>

unsigned random_gen(unsigned seed = time(0), 
                    unsigned minv = 0, 
                    unsigned maxv = 2147483646) {
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> u(minv, maxv);
    return u(e);
}

int main() {
    //std::cout << random_gen() << std::endl;
    //std::cout << random_gen(1024) << std::endl;
    std::cout << random_gen(123, 10, 15) << std::endl;
    //std::cout << random_gen(0,2147483644) << std::endl;

    return 0;
}