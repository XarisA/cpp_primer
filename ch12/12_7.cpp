#include <iostream>
#include <vector>
#include <memory>

auto dynamic_mem() {
    return std::make_shared<std::vector<int>>();
}

void populate(std::shared_ptr<std::vector<int>> vp) {
    int i;
    while (std::cin >> i) {
        vp->push_back(i);
    }
}

void print(std::shared_ptr<std::vector<int>> vp) {
    for (const int i : *vp) {
        std::cout << i << ' ';
    } 
    std::cout << std::endl;
}

int main() {
    auto vp = dynamic_mem();
    populate(vp);
    print(vp);

    return 0;
}