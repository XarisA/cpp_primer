#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using std::istringstream;
using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char** argv) {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream in(argv[1]);

    while (getline(in, line)) {
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