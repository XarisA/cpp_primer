#include <iostream>

template <typename T>
void print(std::ostream &os, T t) {
    os << t << std::endl;
}

template <typename T, typename ... Args>
void print(std::ostream &os, T t, Args ... args) {
    os << t << ' ';
    print(os, args ...);
}

struct A { };

int main() {
    print(std::cout, "haha", 66, 1.2, 'c');

    /*
    compile error
    print(std::cout, A());
    */

    return 0;
}