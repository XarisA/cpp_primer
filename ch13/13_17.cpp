#include <iostream>

class numbered {
public:
    numbered() {
        mysn = unique++;
    }
    static int unique;
    int mysn;
};

class numberedv2 {
public:
    numberedv2() {
        mysn = unique++;
    }
    numberedv2(const numberedv2&) {
        mysn = unique++;
    }
    static int unique;
    int mysn;
};

void f14(numbered s) {std::cout << s.mysn << std::endl;}
void f15(numberedv2 s) {std::cout << s.mysn << std::endl;}
void f16(const numbered& s) {std::cout << s.mysn << std::endl;}

int numbered::unique = 10;
int numberedv2::unique = 100;

int main() {
    // ex 13.14
    {
    numbered a, b = a, c = b;
    f14(a); f14(b); f14(c);
    }

    // ex 13.15
    {
    numberedv2 a, b = a, c = b;     // 100, 101, 102
    f15(a); f15(b); f15(c);         // 103, 104, 105
    }

    // ex 13.16
    {
    numbered a, b = a, c = b;
    f16(a); f16(b); f16(c);
    }
}