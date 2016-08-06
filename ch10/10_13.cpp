#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::partition;

bool isLongerThanFive(const string &s) {
    return s.size() > 4;
}

int main() {
    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto p = partition(vec.begin(), vec.end(), isLongerThanFive);
    auto beg = vec.begin();
    while (beg != p) {
        cout << *beg++ << ' ';
    }
    cout << endl;

    return 0;
}