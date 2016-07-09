#include <iostream>

using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    int *p = begin(arr);
    int *arrEnd = end(arr);
    while (p < arrEnd) {
        *p = 0;
        ++p;
    }
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}