#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int n;
    while (cin >> n) {
        numbers.push_back(n);
    }
    for (int i = 1; i < numbers.size(); ++i) {
        cout << numbers[i-1] + numbers[i] << " ";
    }
    cout << endl;
    decltype(numbers.size()) i = 0;
    auto j = numbers.size() - 1;
    while (i++ < j--) {
        cout << numbers[i] + numbers[j] << " ";
    }
    if (i == j)
        cout << numbers[i] << " ";
    cout << endl;
    return 0;
}
