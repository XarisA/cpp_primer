#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::stable_sort;
using std::unique;
using std::sort;
using std::find_if;
using std::for_each;
using std::stable_partition;

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending = "s") {    // copy from ex 6.42
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), [] (const string &s1, const string &s2) { return s1.size() < s2.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [] (const string &s) { cout << s << ' '; });
    cout << endl;
}

// ex 10.18 : using partition instead of find_if
// ex 10.19 : using stable_partition instead of partition
void biggies_ptn(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), [] (const string &s1, const string &s2) { return s1.size() < s2.size(); });
    auto wc = stable_partition(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
    auto count = wc - words.begin();
    cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), wc, [] (const string &s) { cout << s << ' '; });
    cout << endl;
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);

    vector<string> words2{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies_ptn(words2, 5);
    return 0;
}