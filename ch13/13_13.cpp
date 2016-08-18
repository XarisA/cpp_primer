#include <iostream>
#include <vector>

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X& operator=(const X &rhs) {std::cout << "X& operator=(const X &rhs)" << std::endl; return *this;}
    ~X() {std::cout << "~X()" << std::endl;}
};

void func(const X& rx, X x) {
    std::cout << "func()" << std::endl;
    std::vector<X> vec;
    vec.push_back(rx);
    vec.push_back(x);
    std::cout << "func(): done" << std::endl;
}

int main() {
    X *p = new X();
    func(*p, *p);
    std::cout << "func(): out of scope" << std::endl;
    delete p;
    return 0;
}