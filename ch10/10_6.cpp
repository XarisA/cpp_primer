#include <algorithm>
#include <iostream>

using std::fill_n;
using std::cout;
using std::endl;
using std::begin;

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fill_n(begin(nums), 10, 0);
    for (int i : nums) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
