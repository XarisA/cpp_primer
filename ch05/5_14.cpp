#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::max;
using std::string;

int main() {
    int maxCnt = 0, currentCnt = 0;
    string curr, last, most;
    while (cin >> curr) {
        if (!last.empty() && curr == last) {
            ++currentCnt;
        } 
        else {
            currentCnt = 1;
            last = curr;
        }
        if (currentCnt > maxCnt) {
            maxCnt = currentCnt;
            most = curr;
        }
    }
    cout << most << ": " << maxCnt << endl;
    return 0;
}