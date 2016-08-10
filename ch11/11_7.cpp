#include <map>
#include <vector>
#include <iostream>

using std::map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
    map<string, vector<string>> name;
    name["Cook"] = {"Tim", "Alex", "Ben"};
    name["Jobs"] = {"Steve", "Lisa", "Tom"};
    name["Underwood"];
    name["Underwood"].push_back("Frank");

    for (const auto &p : name) {
        cout << "Family name: " << p.first << endl;
        for (const auto &s : p.second) {
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}