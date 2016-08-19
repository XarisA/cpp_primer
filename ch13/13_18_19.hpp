#ifndef EMPLOYEE
#define EMPLOYEE

#include <string>

class Employee {
public:
    Employee() : id(unique++) {}
    Employee(const std::string n) : name(n), id(unique++) {}
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
    static int unique;
private:
    std::string name;
    int id;
};

#endif