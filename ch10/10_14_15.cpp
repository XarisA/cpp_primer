#include <iostream>

using std::cout;
using std::endl;

// ex 10.15
int plusFive(const int i) {
    int plus = 5;
    auto pFive = [plus] (const int i) { return i + plus; };
    return pFive(i);
}

int main() {
    // ex 10.14
    auto mySum = [] (const int i, const int j) { return i + j; };
    cout << mySum(5, 6) << endl;

    cout << plusFive(10) << endl;

    return 0;
}