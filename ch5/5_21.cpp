#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    string curr, last;
    while (cin >> curr) {
        if (!isupper(curr[0])) {
            continue;
        }   // terminates this iteration
        if (curr == last) {
            break;
        } 
        else {
            last = curr;
        }
    }
    if (cin.eof()) {
        cout << "No word was repeated" << endl;
    }
    else {
        cout << last << endl;
    }
    return 0;
}