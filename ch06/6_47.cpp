#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_contents(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin != end) {
        #ifndef NDEBUG
        std::cerr << "Size: " << end - begin << endl;
        #endif
        cout << *begin << endl;
        print_contents(begin + 1, end);
    }
}

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8};
    print_contents(vi.begin(), vi.end());
    return 0;
}