#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::count_if;

bool check6(const string &s) {
    return s.size() > 6;
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "longest"};
    auto count = count_if(words.begin(), words.end(), [] (const string &s) { return s.size() > 6; });
    cout << count << endl;

    auto fcount = count_if(words.begin(), words.end(), check6);
    cout << fcount << endl;

    return 0;
}