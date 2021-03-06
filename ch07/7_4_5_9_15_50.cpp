#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;
using std::istream;

struct Person {
    string name;
    string address;
    string getName() const;
    string getAddress() const;
    Person() = default;
    Person(const string &n, const string &a) : name(n), address(a) {};
    explicit Person(const string &n) : name(n) {};
    explicit Person(istream &is);
};

string Person::getName() const {
    return name;
}

string Person::getAddress() const {
    return address;
}

istream &read(istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

ostream &print(ostream &os, const Person &p) {
    os << p.getName() << ' ' << p.getAddress();
    return os;
}

Person::Person(istream &is) {
    read(is, *this);
}

int main() {
    Person p;
    p.name = "John";
    p.address = "213 Fake St.";
    cout << p.getName() << ' ' << p.getAddress() << endl;
    read(cin, p);
    print(cout, p) << endl;
    return 0;
}