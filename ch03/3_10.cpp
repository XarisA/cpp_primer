#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    string result;
    for (auto &c : s) {
        if (ispunct(c))
            continue;
        result += c;
    }
    cout << result << endl;
}
