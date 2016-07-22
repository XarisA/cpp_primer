#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const char *p) {
    if (p) {
        while (*p) {
            cout << *p++ << endl;
        }
    }
}

void print(const int *p) {
    if (p) {
        cout << *p << endl;
    }
}

void print(const int *begin, const int *end) {
    while (begin != end) {
        cout << *begin++ << endl;
    }
}

void print(const int *p, size_t size){
    for (size_t i = 0; i < size; ++i) {
        cout << *(p + i) << endl;       // equivalent to p[i]
    }
}

int main() {
    int i = 0, j[2] = {0, 1};
    char str[6] = "Hello";
    print(&i);
    print(begin(j), end(j));
    print(j, end(j) - begin(j));
    print(str);

    return 0;
}