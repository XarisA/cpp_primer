#include <list>
#include <algorithm>
#include <iostream>

using std::list;
using std::string;
using std::cout;
using std::endl;
using std::unique;
using std::sort;

void elimDups(list<string> &words) {
    words.sort();
    words.unique();
}

int main() {
    list<string> lst{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(lst);
    for (const string &s : lst) {
        cout << s << ' ';
    }
    cout << endl;

    return 0;
}