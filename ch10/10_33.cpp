#include <iterator>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    ofstream odd(argv[2]), even(argv[3]);
    istream_iterator<int> is_iter(in), eof;
    ostream_iterator<int> odd_iter(odd, " "), even_iter(even, "\n");
    while (is_iter != eof) {
        if (*is_iter % 2 == 1) {     // odd
            odd_iter = *is_iter;
        }
        else {
            even_iter = *is_iter;
        }
        ++is_iter;
    }

    return 0;
}