#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::sort;
using std::unique_copy;
using std::back_inserter;

int main() {
    vector<int> vec{1, 1, 2, 3, 4, 5, 6, 5};
    list<int> lst;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));    // the vector must to be sorted
    for (const auto i : lst) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}