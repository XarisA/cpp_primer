#include <vector>
#include <algorithm>
#include <iostream>

class isEqual {
public:
    isEqual(int val) : value(val) {}
    bool operator()(int elem) {
        return value == elem;
    }
private:
    int value;
};

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    isEqual ie(5);
    std::replace_if(vec.begin(), vec.end(), ie, -1);
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}