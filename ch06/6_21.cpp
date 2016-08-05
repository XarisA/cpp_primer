#include <iostream>

using std::cout;
using std::endl;

int larger(const int i, const int &j) {
    return (i > j) ? i : j;
}

int main() {
    int i = 3;
    int j = 2;
    int &rj = j;
    cout << i << ' ' << rj << endl;
    cout << larger(i , rj) << endl;
    return 0;
}