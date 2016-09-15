#include <iostream>
#include <vector>

template <typename T>
void print(const T& container) {
    for(typename T::size_type i = 0; i != container.size(); ++i) {
        std::cout << container[i] << ' ';
    }
}

template <typename T>
void print_iter(const T& container) {
    for(auto p = container.cbegin(); p != container.cend(); ++p) {
        std::cout << *p << ' ';
    }
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    print(vec);
    std::cout << std::endl;
    print_iter(vec);
    return 0;
}