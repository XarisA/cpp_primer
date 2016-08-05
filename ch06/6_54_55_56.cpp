#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int func(int, int);
using FP = int (*)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    vector<FP> vfp;
    FP f1 = add, f2 = subtract, f3 = multiply, f4 = divide;
    vfp.push_back(f1);
    vfp.push_back(f2);
    vfp.push_back(f3);
    vfp.push_back(f4);
    int a = 10, b = 2;
    for (auto &r : vfp) {
        cout << r(a, b) << endl;
    }
    return 0;
}