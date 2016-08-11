#include <vector>
#include <utility>
#include <iostream>

using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;
using std::cin;

int main() {
    vector<pair<string, int>> vec;
    string s;
    int i;
    while (cin >> s >> i) {
        vec.push_back({s, i});
        //vec.push_back(make_pair(s, i));
        //vec.push_back(pair<string, int>(s, i));
    }

    for (const auto &v : vec) {
        cout << v.first << ' ' << v.second << endl;
    }

    return 0;
}