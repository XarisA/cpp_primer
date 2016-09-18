#include <iostream>
#include <utility>

void func(int i, int &&j) {
    std::cout << i << " " << j << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

int main() {
    int i = 42;
    flip(func , i, 1024);
    return 0;
}