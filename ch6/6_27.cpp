#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> list) {
    int result = 0;
    for (auto &i : list) {
        result += i;
    }
    return result;
}

int main() {
    int result = sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    cout << result << endl;
    return 0;
}