#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::front_inserter;
using std::back_inserter;
using std::inserter;
using std::copy;

void print(const vector<int> &vec) {
    for (const int i : vec) {
        cout << i << ' ';
    }
    cout << endl;
}

void print(const list<int> &vec) {
    for (const int i : vec) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v1, v2;
    list<int> l1;
    
    copy(vec.begin(), vec.end(), front_inserter(l1));
    copy(vec.begin(), vec.end(), back_inserter(v1));
    copy(vec.begin(), vec.end(), inserter(v2, v2.begin()));

    print(l1);
    print(v1);
    print(v2);

    return 0;
}
