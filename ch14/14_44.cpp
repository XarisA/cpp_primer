#include <iostream>
#include <map>

int add(int i, int j) { return i + j; }
auto mod = [](int i , int j) { return i % j; };
struct divide {
    int operator()(int i, int j) { return i / j; }
};

int main() {
    std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"*", [](int i, int j) { return i * j; }},
        {"/", divide()},
        {"%", mod}
    };
    while (true) {
        int lhs, rhs;
        std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << (binops[op](lhs, rhs)) << std::endl;
    }
}