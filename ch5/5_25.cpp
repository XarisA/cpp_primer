#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::invalid_argument;

int division(int a, int b) {
    if (b == 0) {
        throw invalid_argument("Cannot divide by zero");
    }
    return (a / b);
}

int main() {
    int a, b, result;
    while (cin >> a >> b) {
        try {
            result = division(a, b);
            cout << result << endl;
        }
        catch (invalid_argument e) {
            cout << e.what() << endl;
            cout << "Try again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
    }
    return 0;
}