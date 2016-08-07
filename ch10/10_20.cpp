#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::count_if;

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "longest"};
    auto count = count_if(words.begin(), words.end(), [] (const string &s) { return s.size() > 6; });
    cout << count << endl;

    return 0;
}