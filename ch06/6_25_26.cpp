#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {
    string s;
    for (int i = 1; i < argc; ++i) {
        s += argv[i];
    }
    cout << s << endl;
    return 0;
}