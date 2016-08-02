#include <vector>
#include <iostream>

using std::vector;

vector<int>::const_iterator find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target) {
    while (begin != end) {
        if (*begin == target) { return begin; }
        ++begin;
    }
    return end;
}

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 9, 10};
    std::cout << *find(vec.begin(), vec.end(), 8) << std::endl;
    std::cout << *find(vec.begin(), vec.end(), 4) << std::endl;
    return 0;
}