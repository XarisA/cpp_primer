#include <memory>
#include <iostream>

int main() {
    std::size_t n = 32;
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n);
    std::string s;
    auto q = p;
    while(std::cin >> s && q != p + n) {
        alloc.construct(q++, s);
    }
    alloc.deallocate(p, n);

    return 0;
}