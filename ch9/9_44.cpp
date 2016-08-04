#include <iostream>

using std::string;
using std::cout;
using std::endl;

void replace_old_with_new(string &s, const string &oldS, const string &newS) {
    for (unsigned curr = 0; curr <= s.size() - oldS.size(); ) {
        if (s[curr] == oldS[0] && s.substr(curr, oldS.size()) == oldS) {
            s.replace(curr, oldS.size(), newS);
            curr += newS.size();
        }
        else {
            ++curr;
        }
    }
}

int main() {
    string s("thru tho");
    replace_old_with_new(s, "tho", "though");
    replace_old_with_new(s, "thru", "through");
    cout << s << endl;
    return 0;
}