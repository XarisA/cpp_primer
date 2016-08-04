#include <iostream>

using std::cout;
using std::endl;
using std::string;

string combine_name(const string &name, const string &prefix, const string &suffix) {
    string fullName(name), space(" ");
    fullName.insert(fullName.begin(), space.cbegin(), space.cend());
    fullName.append(space);
    fullName.insert(fullName.begin(), prefix.cbegin(), prefix.cend());
    fullName.append(suffix);
    return fullName;
}

int main() {
    string name("Tom Hanks"), prefix("Mr."), suffix("Jr.");
    cout << combine_name(name, prefix, suffix) << endl;
    return 0;
}
