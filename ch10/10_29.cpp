#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::copy;

int main(int argc, char** argv) {
    vector<string> vec;
    auto in = ifstream(argv[1]);
    istream_iterator<string> s_iter(in), eof;
    while (s_iter != eof) {
        vec.push_back(*s_iter++);
    }

    ostream_iterator<string> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    return 0;
}