#include <iostream>

using std::cout;
using std::endl;
using std::string;

string combine_name(const string &name, const string &prefix, const string &suffix) {
    string fullName(name);
    fullName.insert(0, " ");
    fullName.insert(fullName.size(), " ");
    fullName.insert(0, prefix);
    fullName.insert(fullName.size(), suffix);
    return fullName;
}

int main() {
    string name("Tom Hanks"), prefix("Mr."), suffix("Jr.");
    cout << combine_name(name, prefix, suffix) << endl;
    return 0;
}