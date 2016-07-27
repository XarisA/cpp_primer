#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct Person {
    string name;
    string address;
    string getName() const;
    string getAddress() const;
};

string Person::getName() const {
    return name;
}

string Person::getAddress() const {
    return address;
}

int main() {
    Person p;
    p.name = "John";
    p.address = "213 Fake St.";
    cout << p.getName() << ' ' << p.getAddress() << endl;
    return 0;
}