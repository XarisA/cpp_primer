#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    int userInput;
    cout << "Input: " << endl;
    cin >> userInput;
    int res = fact(userInput);
    cout << res << endl;
    return 0;
}