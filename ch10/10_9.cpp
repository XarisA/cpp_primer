#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::sort;
using std::unique;

void print(const vector<string> &s) {
    for (auto &word : s) {
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

int main() {
    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);

    return 0;
}
