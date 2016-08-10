#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::find;

int main() {
    string word;
    vector<string> excluded{"abc", "aaa", "abd"};
    cin >> word;
    auto found = find(excluded.cbegin(), excluded.cend(), word);        // searching in a unsorted vector takes O(n) time, while it only takes O(1) in a set
    cout << (found == excluded.end() ? "not excluded" : "excluded") << endl;

    return 0;
}