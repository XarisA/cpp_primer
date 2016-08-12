#include <map>
#include <iostream>
#include <utility>
#include <set>

using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::set;
using std::pair;

int main() {
    multimap<string, string> works;
    works.insert({"Author3", "Book6"});
    works.insert({"Author1", "Book1"});
    works.insert({"Author1", "Book2"});
    works.insert({"Author1", "Book3"});
    works.insert({"Author2", "Book4"});
    works.insert({"Author3", "Book5"});

    auto found = works.find("Author1");
    auto count = works.count("Author1");
    
    while (count) {
        if (found->second == "Book1") {
            works.erase(found);
            break;
        }
        --count;
        ++found;
    }

    for (const auto &p : works) {
        cout << p.first << ' ' << p.second << endl;
    }

    // ex 11.32
    set<pair<string, string>> sorted;
    for (const auto &p : works) {
        sorted.insert({p.first, p.second});
    }

    cout << "Sorted:" << endl;
    for (const auto &p : sorted) {
        cout << p.first << ' ' << p.second << endl;
    }    

    return 0;
}