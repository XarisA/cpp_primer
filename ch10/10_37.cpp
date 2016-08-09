#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::copy;
using std::back_inserter;

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    list<int> lst;
    copy(vec.crbegin() + 3, vec.crend() - 3, back_inserter(lst));
    for (const auto i : lst){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}