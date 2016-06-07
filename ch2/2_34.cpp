#include <iostream>

using namespace std;

int main() {
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    cout << "Variables before assignments: " << a << " " << b << " " << c << " " << d << " " << e << " " << g << endl;
    a = 42;
    b = 42;
    c = 42;
    //d = 42; // ERROR
    //e = 42; // ERROR
    //g = 42; // ERROR
    cout << "Variables after assignments: " << a << " " << b << " " << c << " " << d << " " << e << " " << g << endl;
    return 0;
}