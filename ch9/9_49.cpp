#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::max;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string word;
    string letters("dfpg");
    unsigned long result = 0;
    while (in >> word) {
        if (word.find_first_of(letters) == string::npos)
            result = max(result, word.size());
    }
    cout << result << endl;
    return 0;
}