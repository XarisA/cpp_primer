#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main() {
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2{1, 2, 4};
    cout << (v1 == v2) << endl;
    vector<int> v3{1, 2, 3, 4, 5, 6, 7, 8};
    cout << (v1 == v3) << endl;
    vector<int> v4{1, 2, 3, 4, 5, 6, 7, 9};
    cout << (v1 == v4) << endl;

    list<int> l1{1, 2, 3, 4, 5, 6, 7, 8};
    //cout << (v1 == l1) << endl;       // error: different container types
    return 0;
}