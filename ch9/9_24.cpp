#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> vec{1, 2, 3, 4};
    cout << vec.at(0) << ' ' <<
            vec[0] << ' ' <<
            vec.front() << ' ' <<
            *vec.begin() << endl;
    vector<int> empty_vec;
    cout << empty_vec.at(0) << ' ' <<       // out of range exception
            empty_vec[0] << ' ' <<          // segmentation fault
            empty_vec.front() << ' ' <<     // segmentation fault
            *empty_vec.begin() << endl;     // segmentation fault
    return 0;
}
