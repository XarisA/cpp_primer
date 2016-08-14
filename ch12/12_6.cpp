#include <iostream>
#include <vector>

std::vector<int>* dynamic_mem() {
    return new std::vector<int>;
}

void populate(std::vector<int> *vp) {
    int i;
    while (std::cin >> i) {
        vp->push_back(i);
    }
}

void print(std::vector<int> *vp) {
    for (const int i : *vp) {
        std::cout << i << ' ';
    } 
    std::cout << std::endl;
}

int main() {
    auto *vp = dynamic_mem();
    populate(vp);
    print(vp);
    delete vp;
    vp = nullptr;

    return 0;
}