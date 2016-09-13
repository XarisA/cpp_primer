#include <iostream>
#include <vector>

template <typename T>
void print(const T& t) {
    for (const auto &i : t) {
        std::cout << i << ' ';
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    print(arr);
    std::cout << std::endl;
    std::string str[] = {"this", "is", "a", "test"};
    print(str);
    std::cout << std::endl;
}

