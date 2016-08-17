#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using namespace std;
using line_no = vector<string>::size_type;

int main(int argc, char **argv) {
    ifstream infile(argv[1]);
    vector<string> text;
    map<string, set<line_no>> lines;
    string line, word;
    while (getline(infile, line)) {
        text.push_back(line);
        auto n = text.size() - 1;
        istringstream iss(line);
        while (iss >> word) {
            lines[word].insert(n);
        }
    }

    // ex 12.29: do while loop
    string s;
    do {
        cout << "enter word to look for, or q to quit: ";
        cin >> s;
        if (lines.find(s) != lines.end()) {
            auto c = lines[s].size();
            cout << s << " occurs " << c << (c > 1 ? " times" : " time") << endl;
            for (const int l : lines[s]) {
                cout << "(line " << l+1 << ") " << text[l] << endl;
            }
        }
    } while (s != "q");

    return 0;
}