#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int abs(int a) {
    if (a < 0) {
        a = -a;
    }
    return a;
}

int main() {
    int numbers[] = {0, -1, 1, 100, -15, 0x7fffffff};
    for (auto n : numbers) {
        cout << abs(n) << endl;
    }
    return 0;
}