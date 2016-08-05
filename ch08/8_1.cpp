#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istream;

istream& readAll(istream &is) {
    string buff;
    while (is >> buff) {
        cout << buff;
    }
    is.clear();
    return is;
}

int main() {
    istream &is = readAll(cin);
    cout << "\nrdstate: " << is.rdstate() << endl;
    return 0;
}