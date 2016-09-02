#include <vector>
#include <iostream>

int main() {
    using std::placeholders::_1;
    std::vector<int> divisor{2, 3, 5};
    std::modulus<int> mod;
    int number;
    while (std::cin >> number) {
        auto p = [&](int i){ return mod(number, i) == 0; };
        auto is_divisible = std::any_of(divisor.cbegin(), divisor.cend(), p);
        std::cout << (is_divisible ? "Yes" : "No") << std::endl;
    }
    return 0;
}