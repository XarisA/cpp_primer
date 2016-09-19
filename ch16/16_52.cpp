#include <iostream>

template <typename T, typename ... Args>
void g(T, Args ... args) {
    std::cout << "Args: " << sizeof...(Args) << std::endl;
    std::cout << "args: " << sizeof...(args) << std::endl;
}

int main() {
    g(1, 2);
    g(1, 1.1);
    char c('c');
    g("this", 8.8, c);
    return 0;
}