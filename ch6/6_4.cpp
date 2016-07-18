#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int fact(int a) {
    int result = 1;
    while (a > 1) {
        result *= a--;
    }
    return result;
}

int main() {
    int userInput;
    cin >> userInput;
    int res = fact(userInput);
    cout << res << endl;
    return 0;
}