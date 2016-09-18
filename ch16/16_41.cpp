#include <iostream>

template <typename T, typename U>
auto sum(T i, U j) -> decltype(i + j) {
    return i + j;
}

int main() {
    auto i = 3;
    int j = 2;
    std::cout << sum(1234567891234567, j) << std::endl;
    std::cout << sum(j, i) << std::endl;
    return 0;
}