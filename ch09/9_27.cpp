#include <forward_list>
#include <iostream>

using std::forward_list;
using std::cout;
using std::endl;

int main() {
    forward_list<int> fl{1, 2, 3, 4, 5, 6, 7, 9, 9, 9, 9, 9};
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while (curr != fl.end()) {
        if (*curr % 2 == 1) {
            curr = fl.erase_after(prev);
        }
        else {
            prev = curr;
            ++curr;
        }
    }

    for (auto i : fl) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}