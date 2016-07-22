#include <iostream>

using std::cout;
using std::endl;

void ptr_swap(int* &i, int* &j) {   // i ,j are references of int pointer
    int *tmp = i;
    i = j;
    j = tmp;
}

int main() {
    int i = 1, j = 2;
    int *ip = &i, *jp = &j;
    cout << *ip << ' ' << *jp << endl;
    ptr_swap(ip, jp);
    cout << *ip << ' ' << *jp << endl;
}