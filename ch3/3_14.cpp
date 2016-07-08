#include <iostream>
#include <vector>

using namespace std;

int main() {
    int single_int;
    vector<int> ints;
    while (cin >> single_int) {
        ints.push_back(single_int);
        cout << single_int << endl;
    }
    return 0;
}

