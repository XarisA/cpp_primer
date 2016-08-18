#ifndef HASPTR_OBJ
#define HASPTR_OBJ

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) { }
                                                    // equivalent to *(orig.ps), see page 166

    HasPtr& operator=(const HasPtr &rhs) {
        if (this != &rhs) {
            std::string* temp = new std::string(*rhs.ps);
            delete ps;
            ps = temp;
            i = rhs.i;
        }
        return *this;
    }                

    ~HasPtr() {
        delete ps;
    }
                                 
private:
    std::string *ps;
    int i;
};

#endif