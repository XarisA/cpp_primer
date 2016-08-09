#include <list>
#include <iostream>
#include <algorithm>

using std::list;
using std::cout;
using std::endl;
using std::find;

int main() {
    list<int> numbers{1, 2, 3, 4, 5, 6, 0, 7, 8, 9};
    auto zero = find(numbers.crbegin(), numbers.crend(), 0);
    if (zero != numbers.crend()) {
        cout << *zero << endl;
    }

    return 0;
}