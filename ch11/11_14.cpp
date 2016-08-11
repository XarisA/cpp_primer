#include <map>
#include <vector>
#include <utility>
#include <iostream>

using std::map;
using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;
using std::cin;

int main() {
    map<string, vector<pair<string, string>>> name;
    name["Underwood"];
    name["Underwood"].push_back({"Frank", "10/24/88"});

    for (const auto &p : name) {
        cout << "Family name: " << p.first << endl;
        for (const auto &s : p.second) {
            cout << s.first << ' ' << s.second << ' ';
        }
        cout << endl;
    }
    return 0;
}