#include <map>
#include <utility>
#include <iostream>

using std::multimap;
using std::string;
using std::pair;
using std::cout;
using std::endl;
using std::cin;
using std::make_pair;

int main() {
    multimap<string, string> name;
    name.insert({"Underwood", "Frank"});
    name.insert({"Underwood", "Mike"});

    for (const auto &p : name) {
        cout << "Family name: " << p.first << endl;
        cout << p.second << endl;
    }
    return 0;
}