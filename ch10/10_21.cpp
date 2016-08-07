#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 42;
    auto dec = [&n] () { return --n > 0; };
    cout << n << endl;
    while (dec());
    cout << n << endl;
    
    return 0;
}