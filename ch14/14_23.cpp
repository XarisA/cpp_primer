#include "../ch13/13_39_40_43.hpp"

StrVec& StrVec::operator=(std::initializer_list<std::string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

int main() {
    StrVec s1 = {"this", "is", "a", "test"};
    return 0;
}