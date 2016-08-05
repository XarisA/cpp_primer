#include <iostream>

using std::cout;
using std::endl;
using std::string;

bool contains_capital(const string &s) {
    for (auto c : s) {
        if (isupper(c)){
            return true;
        }
    }
    return false;
}

void to_lower(string &s) {
    for (auto &c : s) {
        c = tolower(c);
    }
}

int main() {
    string s1 = "Hello, World!";
    bool res = contains_capital(s1);
    cout << s1 << ' ' << res << endl;
    to_lower(s1);
    res = contains_capital(s1);
    cout << s1 << ' ' << res << endl;
    return 0;
}