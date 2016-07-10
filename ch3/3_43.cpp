#include <iostream>

using namespace std;

int main() {
    int ia[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    
    // using range for
    for (int (&row)[4] : ia)
        for (int &i: row)
            cout << i << ' ';
    cout << endl;

    // for loop with subcripts
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 4; ++j)
            cout << ia[i][j] << ' ';
    cout << endl;

    // for loop with pointers
    for (int (*p)[4] = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
    cout << endl;

    // auto
    for (auto p = ia; p != ia + 3; ++p)
        for (auto q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
    cout << endl;

    // type alias
    using int_array = int[4];
    for (int_array *p = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
    cout << endl;

    return 0;
}