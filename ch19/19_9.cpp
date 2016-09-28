#include <iostream>
#include <typeinfo>
#include <cstring>
#include "../ch14/14_6_9.hpp"       // Sales_data header

class Base { };

class Derived : public Base { };

const char* readable_name(const char *p) {
    if (std::strcmp(p, "i") == 0)
        return "int";
    else if (std::strcmp(p, "A10_i") == 0)
        return "int array that has size of 10";
    else if (std::strcmp(p, "10Sales_data") == 0)
        return "Sales_data object";
    else if (std::strcmp(p, "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE") == 0)
        return "std::string object";
    else if (std::strcmp(p, "P4Base") == 0)
        return "pointer to Base";
    else if (std::strcmp(p, "4Base") == 0)
        return "Base object";
    else
        return p;
}

int main() {
    int arr[10];
    Derived d;
    Base *p = &d;

    std::cout << readable_name(typeid(42).name()) << ", "
            << readable_name(typeid(arr).name()) << ", "
            << readable_name(typeid(Sales_data).name()) << ", "
            << readable_name(typeid(std::string).name()) << ", "
            << readable_name(typeid(p).name()) << ", "
            << readable_name(typeid(*p).name()) << std::endl;

    return 0;
}