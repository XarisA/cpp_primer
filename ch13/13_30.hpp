#ifndef HASPTR_OBJ
#define HASPTR_OBJ

#include <string>
#include <iostream>

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
    HasPtr& operator=(const HasPtr &rhs) {
        auto newp = new std::string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }
    bool operator<(const HasPtr &rhs) const {
        return *ps < *rhs.ps;
    }

    ~HasPtr() { delete ps; }
    void show() const { std::cout << *ps << std::endl; }
private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &h1, HasPtr &h2) {
    std::cout << "Swap two objects" << std::endl;
    using std::swap;
    swap(h1.ps, h2.ps);
    swap(h1.i, h2.i);
}

#endif