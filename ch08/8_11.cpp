#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::istringstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(cin, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    for (auto p = people.begin(); p != people.end(); ++p) {
        cout << p->name << endl;
    }
    return 0;
}