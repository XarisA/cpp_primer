#include <vector>
#include <iostream>
#include <algorithm>

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};

Foo Foo::sorted() && {
    std::cout << "&&" << std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    std::cout << "const &" << std::endl;
    return Foo(*this).sorted();
}

int main() {
    Foo().sorted();
    Foo f;
    f.sorted();

    return 0;
}