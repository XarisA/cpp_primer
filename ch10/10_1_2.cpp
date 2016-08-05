#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

using std::count;
using std::string;
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
    vector<int> vec{1, 1, 2, 3, 4, 1, 5, 1, 1, 1};      // 6 of 1's
    cout << count(vec.cbegin(), vec.cend(), 1) << endl;

    list<string> lst{"aa", "b", "ccc", "aa", "ddddd"};
    cout << count(lst.cbegin(), lst.cend(), "aa") << endl;

    return 0;    
}