#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::end;
using std::cout;
using std::endl;

int main() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> vec(ia, end(ia));
    vector<int> lst(ia, end(ia));
    auto iter = vec.begin();
    while (iter != vec.end()) {
        if (*iter % 2 == 0) {
            iter = vec.erase(iter);
        }
        else {
            ++iter;
        }
    }

    auto iter2 = lst.begin();
    while (iter2 != lst.end()) {
        if (*iter2 % 2 == 1) {
            iter2 = lst.erase(iter2);
        }
        else {
            ++iter2;
        }
    }

    for (auto i : lst) {
        cout << i << ' ';
    }
    cout << endl;
    
    for (auto i : vec) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}