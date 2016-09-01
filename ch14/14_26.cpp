#include "../ch12/12_19.hpp"
#include "../ch13/13_39_40_43.hpp"
#include "../ch13/13_44_47.hpp"
#include <algorithm>

std::string& StrBlob::operator[](std::size_t n) {
    return data->at(n);
}

const std::string& StrBlob::operator[](std::size_t n) const {
    return data->at(n);
}

std::string& StrBlobPtr::operator[](std::size_t n) {
    auto p = check(n, "index out of range");
    return (*p)[n];
}

const std::string& StrBlobPtr::operator[](std::size_t n) const {
    auto p = check(n, "index out of range");
    return (*p)[n];
}

std::string& StrVec::operator[](std::size_t n) {
    return *(elements + n);
}

const std::string& StrVec::operator[](std::size_t n) const {
    return *(elements + n);
}

char& String::operator[](std::size_t n) {
    return *(cStringBegin + n);
}

const char& String::operator[](std::size_t n) const {
    return *(cStringBegin + n);
}

int main() {

}