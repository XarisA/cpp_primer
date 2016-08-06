#include <iostream>
#include <vector>
#include <numeric>      // why the hell accumulate is not in algorithm header?

using std::accumulate;
using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
    int result = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << result << endl;

    vector<double> doubleVec{1.11, 2.22, 3.33};
    auto res = accumulate(doubleVec.cbegin(), doubleVec.cend(), 0);     // lost precision due to the third argument, function returns a int instead of double 
    cout << res << endl;

    return 0;
}