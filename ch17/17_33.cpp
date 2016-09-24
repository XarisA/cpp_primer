#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stdexcept>
#include <random>

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;
using std::vector;
using std::istringstream;
using std::runtime_error;

static std::default_random_engine engine(time(0));

map<string, vector<string>> build_map(ifstream &map_file) {
    map<string, vector<string>> trans_map;
    string key, values;
    while (map_file >> key && getline(map_file, values)) {
        if (values.size() > 1) {
            istringstream is(values);
            string value;
            while (is >> value) {
                trans_map[key].push_back(value);
            }
        }
        else {
            throw runtime_error("No rule for " + key);
        }
    }
    return trans_map;
}

const string& transform(const string &word, 
                        map<string, vector<string>> &trans_map) {
    auto map_it = trans_map.find(word);
    if (map_it != trans_map.end()) {
        std::uniform_int_distribution<unsigned> u(0, map_it->second.size() - 1);
        return map_it->second[u(engine)];
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
            if (firstword)  firstword = false;
            else            cout << ' ';
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