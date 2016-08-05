#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<unsigned> scores(11, 0);
    unsigned grade;
    auto begin = scores.begin();
    while (cin >> grade) {
        if (grade <= 100) {
            auto it = begin + (grade / 10);
            (*it)++;
        }
    }
    for (auto it = scores.begin(); it != scores.end(); ++ it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
