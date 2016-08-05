#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<string> vec{"1", "2", "+235", "-376", "0", "-1"};
    int sums = 0;
    for (auto &s : vec) {
        sums += stoi(s);
    }
    cout << sums << endl;

    vector<string> floats{"12.34", "56.78", ".333333", "6.00", "-12.301", "+56.88", "0.00", "7"};
    float sumF = 0.0;
    for (auto &s : floats) {
        sumF += stod(s);
    }
    cout << sumF << endl;

    return 0;
}