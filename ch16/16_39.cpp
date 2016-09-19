#include <iostream>
#include <functional>

template <typename T> int compare(const T &a, const T &b) {
    if(std::less<T>()(a, b)) return -1;
    if(std::less<T>()(b, a)) return 1;
    return 0;
} 

int main() {
    std::cout << compare("b", "a") << std::endl;
    std::cout << compare<char*>("a", "b") << std::endl;
    std::cout << compare<std::string>("this", "that") << std::endl;
    std::cout << compare<std::string>("a", "b") << std::endl;
    std::cout << compare<std::string>("b", "a") << std::endl;
}