#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::istringstream;

istream& readAll(istream &is) {
    string buff;
    while (is >> buff) {
        cout << buff;
    }
    is.clear();
    return is;
}

int main() {
    string s("this is a test string.");
    istringstream is(s);
    readAll(is);
    return 0;
}