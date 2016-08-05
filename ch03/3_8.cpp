#include <iostream>

using namespace std;

int main() {
    string input = "abcdef12345";
    cout << input << endl;
    for (auto &c : input)       // range for
        c = 'X';
    cout << input << endl;

    input = "abcdef12345";
    cout << input << endl;
    decltype(input.size()) index = 0;
    while (index < input.size())    // while
        input[index++] = 'X';
    cout << input << endl;

    input = "abcdef12345";
    cout << input << endl;
    for (int i = 0; i < input.size(); ++i) {    // traditional for
        input[i] = 'X';
    }
    cout << input << endl;
}
