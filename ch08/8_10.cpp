#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    vector<string> vec;
    if (in) {
        string buff;
        while (getline(in, buff)) {
            vec.push_back(buff);
        }
    }
    for (auto i = vec.begin(); i!= vec.end(); ++i) {
        istringstream is(*i);
        string word;
        while (is >> word) {
            cout << word << endl;
        }
    }
    return 0;
}