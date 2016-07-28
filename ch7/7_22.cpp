#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;
using std::istream;

class Person {
    friend istream &read(istream &is, Person &p);
    friend ostream &print(ostream &os, const Person &p);
    private:
        string name;
        string address;
        
    public:
        Person() = default;
        Person(const string &n) : name(n) {};
        Person(const string &n, const string &a) : name(n), address(a) {};
        string getName() const;
        string getAddress() const;
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

int main() {
    Person p = Person("John", "213 Fake St.");
    cout << p.getName() << ' ' << p.getAddress() << endl;
    read(cin, p);
    print(cout, p) << endl;
    return 0;
}