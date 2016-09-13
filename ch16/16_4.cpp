#include <iostream>
#include <vector>
#include <list>

template <typename I, typename T>
I my_find(I beg, I end, const T& target) {
    for (auto p = beg; p != end; ++p) {
        if (*p == target) return p;
    }
    return end;
}

int main() {
    std::list<std::string> lst{"this", "is", "a", "list", "of", "string"};
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    auto fl = my_find(lst.begin(), lst.end(), "of");
    auto fv = my_find(vec.begin(), vec.end(), 3);
    if (fl != lst.end()) {
        std::cout << *fl << std::endl;
    }    
    if (fv != vec.end()) {
        std::cout << *fv << std::endl;
    }
    
    return 0;
}

