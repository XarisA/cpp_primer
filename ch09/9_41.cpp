#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
    vector<char> vec{'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
    string s(vec.cbegin(), vec.cbegin());
    cout << s << endl;
    return 0;
}
