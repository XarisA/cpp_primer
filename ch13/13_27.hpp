#ifndef HASPTR_OBJ
#define HASPTR_OBJ

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), use(new std::size_t(1)), i(0) {}
    HasPtr(const HasPtr &p) : ps(p.ps), use(p.use), i(p.i) { ++*use; }
    HasPtr& operator=(const HasPtr &rhs) {
        ++*rhs.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;

    }
    ~HasPtr() {
        if(--*use == 0) {
            delete use;
            delete ps;
        }
    }
private:
    std::size_t *use;
    std::string *ps;
    int i;
};

#endif