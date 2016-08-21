#include "13_30.hpp"
#include <vector>
#include <algorithm>

int main() {
    std::vector<HasPtr> vec;
    vec.push_back(HasPtr("p3"));
    vec.push_back(HasPtr("p8"));
    vec.push_back(HasPtr("p1"));
    vec.push_back(HasPtr("p9"));
    std::sort(vec.begin(), vec.end());
    for (const auto &h : vec) {
        h.show(); 
    }

}