#include <iostream>

using std::string;
using std::cout;
using std::endl;

void replace_old_with_new(string &s, const string &oldS, const string &newS) {
    for (auto curr = s.begin(); curr <= s.end() - oldS.size(); ) {
        if (string{curr, curr + oldS.size()} == oldS) {
            curr = s.erase(curr, curr + oldS.size());
            curr = s.insert(curr, newS.begin(), newS.end());
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