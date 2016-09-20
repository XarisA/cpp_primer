#include <vector>
#include <iostream>

template <typename T>
size_t count(const std::vector<T> &vec, T t) {
    size_t cnt = 0;
    for (const auto &n : vec) {
        if (n == t)   ++cnt;
    }
    return cnt;
}

// template <>
// size_t count(const std::vector<std::string> &vec, const char* const &p) {
//     std::cout << "Specialization" << std::endl;
//     auto s = std::string(p);
//     size_t cnt = 0;
//     for (const auto &n : vec) {
//         if (n == s)   ++cnt;
//     }
//     return cnt;
// }

template <>
size_t count(const std::vector<const char*> &vec, const char* p) {
    size_t cnt = 0;
    for (const auto &n : vec) 
        if (strcmp(n, p) == 0)  ++cnt;
    return cnt;
}

int main() {
    std::vector<std::string> vs{"this", "that", "this"};
    std::vector<double> vd{1.1, 2.2, 3.3, 1.1, 4.4, 3.3};
    std::vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    
    std::cout << count(vs, std::string("this")) << std::endl;
    // const char *p = "this";
    // std::cout << count(vs, p) << std::endl;
    std::cout << count(vd, 3.3) << std::endl;
    std::cout << count(vi, 1) << std::endl;
    std::cout << count(vi, 0) << std::endl;

    // ex 16.64
    std::vector<const char*> vc{"this", "this", "that"};
    std::cout << count(vc, "this") << std::endl;

    return 0;
}