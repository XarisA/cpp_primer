#include <iostream>

using std::cout;
using std::endl;

void reset(int &i) {
     i = 0;
}

int main() {
    int i = 3;
    cout << i << endl;
    reset(i);
    cout << i << endl;
    return 0;
}