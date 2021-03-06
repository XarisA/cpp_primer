#ifndef STR_BLOB_PTR
#define STR_BLOB_PTR

#include "12_2.hpp"

class StrBlob;

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
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
    std::string& operator[](std::size_t);
    const std::string& operator[](std::size_t) const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr& operator+=(const size_t);
    StrBlobPtr& operator-=(const size_t);
    StrBlobPtr operator+(const size_t) const;
    StrBlobPtr operator-(const size_t) const;
    std::string* operator->() const;
    std::string& operator*() const;
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

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    const std::string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr() {
        check(curr, "increment past end of ConstStrBlobPtr");
        ++curr;
        return *this;
    }
    bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
    const std::string* operator->() const;
    const std::string& operator*() const;
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t sz, const std::string &msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw std::runtime_error("unbound ConstStrBlobPtr");
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