#include "../ch12/12_19.hpp"

StrBlobPtr& StrBlobPtr::operator+=(const size_t n) {
    curr += n;
    check(curr, "index out of range");
    return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(const size_t n) {
    curr -= n;
    check(curr, "index out of range");
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(const size_t n) const {
    StrBlobPtr ret = *this;
    ret.curr += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(const size_t n) const {
    StrBlobPtr ret = *this;
    ret.curr -= n;
    return ret;
}

int main() {

}