#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::sort;
using std::stable_sort;
using std::unique;

void print(const vector<string> &s) {
    for (const auto &word : s) {
        cout << word << ' ';
    }
    cout << endl;
}

void elimDups(vector<string> &words) {
    print(words);
    sort(words.begin(), words.end());
    print(words);
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    print(words);
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main() {
    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);

    stable_sort(vec.begin(), vec.end(), isShorter);
    print(vec);

    return 0;
}
