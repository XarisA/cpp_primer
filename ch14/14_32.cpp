#include "../ch12/12_19.hpp"

class StrBlobPtrPtr {
public:
    StrBlobPtrPtr() = default;
    StrBlobPtrPtr(StrBlobPtr *sp) : p(sp) {}
    StrBlobPtr& operator*() const {
        return *p;
    }
    StrBlobPtr* operator->() const {
        return p;
    }
private:
    StrBlobPtr *p = nullptr;
};

int main() {

}