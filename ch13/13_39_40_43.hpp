#ifndef STRVEC
#define STRVEC

#include <string>
#include <memory>
#include <utility>

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {};
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec&);
    ~StrVec() { free(); };
    void push_back(const std::string&);
    void reserve(const size_t);
    void resize(const size_t, const std::string& s = std::string(""));
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate(const size_t n = 0);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s) {
    auto temp = alloc_n_copy(s.begin(), s.end());
    elements = temp.first;
    cap = first_free = temp.second;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto temp = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = temp.first;
    cap = first_free = temp.second;
    return *this;
}

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        /*
        Ex. 13.43 : is this going to destroy elements in reverse order?
        for_each(elements, first_free, [this](const std::string &rhs){ alloc.destroy(&rhs); });
        */
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate(const size_t n) {
    size_t newCap = size() ? size() * 2 : 1;
    while (newCap - size() < n) {
        newCap *= 2;
    }
    auto newData = alloc.allocate(newCap);
    auto dest = newData;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCap;
}

void StrVec::reserve(const size_t n) {
    if (capacity() - size() < n) {
        reallocate(n);
    }
}

void StrVec::resize(const size_t n, const std::string& s) {
    if (n > size()) {  
        if (n > capacity()) {
            reserve(n - capacity());
        }
        for (size_t i = 0; i != n - size(); ++i) {
            alloc.construct(first_free++, s);
        }
    }
    else {              // shrink
        for (auto p = first_free; p != elements + n; ) {
            alloc.destroy(--p);
        }
    }
}

StrVec::StrVec(std::initializer_list<std::string> l) {
    auto data = alloc_n_copy(l.begin(), l.end());
    elements = data.first;
    cap = first_free = data.second;
}

#endif