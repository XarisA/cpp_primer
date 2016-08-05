#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void print_size_and_capacity(vector<int> &v) {
    cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
}

int main() {
    vector<int> vec;
    print_size_and_capacity(vec);
    auto vcap = vec.capacity();
    for (int i = 0; i != 100; ++i) {
        vec.push_back(i);
        if (vec.capacity() != vcap) {
            print_size_and_capacity(vec);
            vcap = vec.capacity();
        }
    }
    return 0;
}