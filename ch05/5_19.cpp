#include <iostream>

using namespace std;

int main() {
    char ctn;
    do {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (s1 > s2 ? s1 : s2) << endl;
        cout << "Continue? Y/N" << endl;
        cin >> ctn;
    }
    while (ctn != 'N');
    return 0;
}