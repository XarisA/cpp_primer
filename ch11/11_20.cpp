#include <map>
#include <iostream>


using std::map;
using std::string;
using std::cin;

int main() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        auto res = word_count.insert({word, 1});
        if (!res.second) {
            ++res.first->second;
        }
    }

    return 0;
}