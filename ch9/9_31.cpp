#include <forward_list>
#include <list>
#include <iostream>

using std::forward_list;
using std::list;
using std::advance;
using std::cout;
using std::endl;

void remove_evens_duplicate_odds(forward_list<int> &l) {
    for (auto prev = l.before_begin(), curr = l.begin(); curr != l.end(); ) {
        if (*curr % 2) {    // odd
            curr = l.insert_after(prev, *curr);
            advance(prev, 2);       // list and forward_list does not support += operator
            advance(curr, 2);
        }
        else {  // even
            curr = l.erase_after(prev);
        }
    }
}

void remove_evens_duplicate_odds(list<int> &l) {
    auto iter = l.begin();
    while (iter != l.end()) {
        if (*iter % 2) {
            iter = l.insert(iter, *iter);
            advance(iter, 2);
        }
        else {
            iter = l.erase(iter);
        }
    }
}

int main() {
    forward_list<int> fl{1, 2, 3, 4, 5, 6, 6, 7, 8, 9};
    remove_evens_duplicate_odds(fl);
    for (auto i: fl) {
        cout << i << ' ';
    }
    cout << endl;

    list<int> l{1, 2, 3, 4, 5, 6, 6, 7, 8, 9};
    remove_evens_duplicate_odds(l);
    for (auto i: l) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}