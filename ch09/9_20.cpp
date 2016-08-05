#include <deque>
#include <list>
#include <iostream>

using std::deque;
using std::list;
using std::cout;
using std::endl;

int main() {
    list<int> lst{1, 2, 3, 4, 5, 6, 7, 9};
    deque<int> odd, even;
    for (auto i : lst) {
        if (i % 2 == 1) {
            odd.push_back(i);
        }
        else {
            even.push_back(i);
        }
    }

    for (auto i : odd) {
        cout << i << ' ';
    }
    cout << endl;

    for (auto i : even) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}