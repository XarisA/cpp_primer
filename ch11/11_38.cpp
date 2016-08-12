#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <stdexcept>

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_map;
using std::string;
using std::istringstream;
using std::runtime_error;

unordered_map<string, string> build_map(ifstream &map_file) {
    unordered_map<string, string> trans_map;
    string key, value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);
        }
        else {
            throw runtime_error("No rule for " + key);
        }
    }
    return trans_map;
}

const string& transform(const string &word, unordered_map<string, string> &trans_map) {
    auto map_it = trans_map.find(word);
    if (map_it != trans_map.end()) {
        return map_it->second;
    }
    else {
        return word;
    }
}

void word_transform(ifstream &map_file, ifstream &input_file) {
    auto trans_map = build_map(map_file);
    string text;
    while (getline(input_file, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword) {
                firstword = false;
            }
            else {
                cout << ' ';
            }
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    ifstream map_file(argv[1]), input_file(argv[2]);
    word_transform(map_file, input_file);

    return 0;
}