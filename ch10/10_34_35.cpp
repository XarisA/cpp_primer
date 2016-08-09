#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6};
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    for (auto it = vec.cend() - 1; it >= vec.cbegin(); --it) {
        cout << *it << ' ';
    }
    cout << endl;
    
    return 0;
}