#include <iostream>

using std::string;
using std::cout;
using std::endl;

string numbers{ "123456789" };
string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

void find_num_and_alphabet_v1(const string &s) {
    string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != string::npos) {
        cout << s[pos] << ' ';
        ++pos;
    }
    cout << endl;
    pos = 0;
    while ((pos = s.find_first_of(alphabet, pos)) != string::npos) {
        cout << s[pos] << ' ';
        ++pos;
    }
    cout << endl;
}

void find_num_and_alphabet_v2(const string &s) {
    for (string::size_type pos = 0; (pos = s.find_first_not_of(alphabet, pos)) != string::npos; ++pos) {
        cout << s[pos] << ' ';
    }
    cout << endl;

    for (string::size_type pos = 0; (pos = s.find_first_not_of(numbers, pos)) != string::npos; ++pos) {
        cout << s[pos] << ' ';
    }
    cout << endl;
}

int main() {
    string s("ab2c3d7R4E6");
    find_num_and_alphabet_v1(s);
    find_num_and_alphabet_v2(s);

    reutrn 0;
}