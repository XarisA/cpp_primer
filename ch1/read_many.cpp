#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item, nextItem;
    std::cin >> item;
    while (std::cin >> nextItem){
        if (item.isbn() == nextItem.isbn())
        {
            item += nextItem;
        }
        else {
            std::cout << "Must be same ISBN!" << std::endl;
            return -1;
        }
    }
    std::cout << item << std::endl;
    return 0;
}
