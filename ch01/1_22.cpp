#include <iostream>
#include "Sales_item.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    Sales_item item, nextItem;
    cin >> item;
    while (cin >> nextItem){
        if (item.isbn() == nextItem.isbn())
        {
            item += nextItem;
        }
        else {
            cout << "Must be same ISBN!" << endl;
            return -1;
        }
    }
    cout << item << endl;
    return 0;
}
