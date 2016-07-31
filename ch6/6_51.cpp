#include <iostream>

using std::cout;
using std::endl;

void f() {
    cout << "f()" << endl;
}

void f(int) {
    cout << "f(int)" << endl;
}

void f(int, int) {
    cout << "f(int, int)" << endl;
}

void f(double, double) {
    cout << "f(double, double)" << endl;
}

int main() {
    /* 
    f(2.56, 42);
    
    error: call to 'f' is ambiguous
    f(2.56, 42);
    ^
    note: candidate function
    void f(int, int) {
        ^
    note: candidate function
    void f(double, double) {
        ^
    1 error generated.
    */
    
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}