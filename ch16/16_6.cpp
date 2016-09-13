#include <iostream>

template <typename T, size_t size>
T* my_begin(T (&t)[size]) { return t; }

template <typename T, size_t size>
T* my_end(T (&t)[size]) { return t + size; }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::string str[] = {"this", "is", "a", "test"};
    std::cout << *my_begin(arr) << *(my_end(str) - 1) << std::endl;

    return 0;
}