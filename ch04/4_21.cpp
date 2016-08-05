#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 4, 5, 9, 33, 45, 46, 77, 91, 100};
    for (auto beg = numbers.begin(); beg != numbers.end(); ++beg) {
        cout << *beg << ' ';
    } 
    cout << endl;

    // conditional operator
    for (auto beg = numbers.begin(); beg != numbers.end(); ++beg) {
        *beg += (*beg % 2 ? 0 : *beg);
    }

    for (auto beg = numbers.begin(); beg != numbers.end(); ++beg) {
        cout << *beg << ' ';
    } 
    cout << endl;
    
    return 0;
}