#include <vector>
#include <iostream>

using std::vector;

bool contains(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target) {
    while (begin != end) {
        if (*begin++ == target) { return true; }
    }
    return false;
}

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 9, 10};
    std::cout << contains(vec.begin(), vec.end(), 8) << std::endl;
    std::cout << contains(vec.begin(), vec.end(), 4) << std::endl;
    return 0;
}