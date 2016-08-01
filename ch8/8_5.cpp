#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    vector<string> vec;
    if (in) {
        string buff;
        while (in >> buff) {
            vec.push_back(buff);
        }
    }
    for (auto i = vec.begin(); i!= vec.end(); ++i) {
        cout << *i << endl;
    }
    return 0;
}