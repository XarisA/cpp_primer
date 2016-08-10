#include <map>
#include <iostream>
#include <algorithm>

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::remove_if;

void lower(string &s) {
    for (auto &c : s)
        c = tolower(c);
}

void strip(string &s) {
    s.erase(remove_if(s.begin(), s.end(), ispunct), s.end());
}

int main() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        lower(word);
        strip(word);
        ++word_count[word];
    }

    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }

    return 0;
}