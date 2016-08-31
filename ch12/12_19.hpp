#ifndef STR_BLOB_PTR
#define STR_BLOB_PTR

#include "12_2.hpp"

class StrBlob;

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t sz, const std::string &msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if (sz >= ret->size()) {
            throw std::out_of_range(msg);
        }
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif