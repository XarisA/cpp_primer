#include <iostream>
#include <sstream>

template <typename T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

template<>
std::string debug_rep(char *p) {
    std::cout << "Specialization" << std::endl;
    return debug_rep(std::string(p));
}

template<>
std::string debug_rep(const char *p) {
    std::cout << "Specialization" << std::endl;
    return debug_rep(std::string(p));
}

int main() {
    char cstr[] = "Hello, World!";
    int i = 5;
    int *pi = &i;
    std::cout << debug_rep(std::string(cstr)) << std::endl;
    std::cout << debug_rep(cstr) << std::endl;
    std::cout << debug_rep(pi) << std::endl;
    return 0;
}