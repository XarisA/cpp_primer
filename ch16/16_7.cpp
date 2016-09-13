#include <iostream>

template <typename T, size_t size>
constexpr size_t get_size(const T (&t)[size]) { return size; }

int main() {
    int arr[] = {1};
    double darr[] = {2.1, 3.5, -11};
    std::cout << get_size(arr) << " " << get_size(darr);

    return 0;
}