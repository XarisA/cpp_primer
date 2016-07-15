#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> v1 = {0, 1, 2, 2}, v2 = {0, 1, 1, 2, 3, 5, 8};
    for (auto p1 = v1.begin(), p2 = v2.begin(); p1 != v1.end() && p2 != v2.end(); ++p1, ++p2) {
        if (*p1 != *p2) {
            cout << "False" << endl;
            return 0;
        }
    }
    cout << "True" << endl;
    return 0;
}