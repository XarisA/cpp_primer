#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

