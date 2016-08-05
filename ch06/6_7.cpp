#include <iostream>

using std::cout;
using std::endl;

int count_call() {
    static int count = 0;
    return count++;
}

int main() {
    for (int i = 0; i < 15; ++i) {
        cout << count_call() << endl;
    }
    return 0;
}