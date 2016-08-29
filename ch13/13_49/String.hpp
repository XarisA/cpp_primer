#ifndef MYSTRING
#define MYSTRING

#include <memory>
#include <algorithm>
#include <iostream>

class String {
public:
    String() : String("") {};
    String(const char*);
    ~String() { free(); };
    String(const String&);
    String(String&&) noexcept;
    String& operator=(const String&);
    String& operator=(String&&) noexcept;
private:
    static std::allocator<char> alloc;
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();
    char *cStringBegin;
    char *cStringEnd;
};

String::String(const char *str) {
    std::cout << "String(const char *str)" << std::endl;
    char *end = const_cast<char*>(str);
    while (*end) {
        ++end;
    }
    range_initializer(str, ++end);
}

std::pair<char*, char*> String::alloc_n_copy(const char *beg, const char *end) {
    auto data = alloc.allocate(end - beg);
    return {data, std::uninitialized_copy(beg, end, data)};
}

void String::range_initializer(const char *begin, const char *end) {
    auto newStr = alloc_n_copy(begin, end);
    cStringBegin = newStr.first;
    cStringEnd = newStr.second;
}

void String::free() {
    if (cStringBegin) {
        std::for_each(cStringBegin, cStringEnd, [this](char &c){alloc.destroy(&c);});
        alloc.deallocate(cStringBegin, cStringEnd - cStringBegin);
    }
}

String& String::operator=(const String &rhs) {
    std::cout << "operator=(const String&)" << std::endl;
    auto newStr = alloc_n_copy(rhs.cStringBegin, rhs.cStringEnd);
    free();
    cStringBegin = newStr.first;
    cStringEnd = newStr.second;
    return *this;
}

String::String(const String &s) {
    std::cout << "String(const String &s)" << std::endl;
    range_initializer(s.cStringBegin, s.cStringEnd);
}

String::String(String &&s) noexcept : cStringBegin(s.cStringBegin), cStringEnd(s.cStringEnd) {
    s.cStringBegin = s.cStringEnd = nullptr;
}

String& String::operator=(String &&rhs) noexcept {
    if (this != &rhs) {
        free();
        cStringBegin = rhs.cStringBegin;
        cStringEnd = rhs.cStringEnd;
        rhs.cStringBegin = rhs.cStringEnd = nullptr;
    }
    return *this;
}

std::allocator<char> String::alloc;

#endif