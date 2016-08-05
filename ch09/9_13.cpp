#include <vector>
#include <list>

using std::vector;
using std::list;

int main() {
    list<int> lst{1, 2, 3, 4, 5, 6};
    vector<int> vec{1, 2, 3, 4, 5, 6};
    vector<double> v1(vec.begin(), vec.end());
    vector<double> v2(lst.begin(), lst.end());
    return 0;
}