#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::copy;
using std::sort;
using std::unique_copy;

int main(int argc, char** argv) {
    vector<int> vec;
    auto in = ifstream(argv[1]);
    istream_iterator<int> iter(in), eof;
    while (iter != eof) {
        vec.push_back(*iter++);
    }

    sort(vec.begin(), vec.end());

    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    unique_copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    return 0;
}