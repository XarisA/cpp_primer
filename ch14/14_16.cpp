#include "../ch12/12_19.hpp"
#include "../ch13/13_39_40_43.hpp"
#include "../ch13/13_44_47.hpp"
#include <iostream>

bool operator==(const StrBlob &s1, const StrBlob &s2) {
    return s1.data == s2.data;
}

bool operator!=(const StrBlob &s1, const StrBlob &s2) {
    return !(s1 == s2);
}

bool operator==(const StrBlobPtr &p1, const StrBlobPtr &p2) {
    return p1.curr == p2.curr;
}

bool operator!=(const StrBlobPtr &p1, const StrBlobPtr &p2) {
    return !(p1 == p2);
}

bool operator==(const StrVec &s1, const StrVec &s2) {
    return s1.elements == s2.elements && s1.first_free == s2.first_free && s1.cap == s2.cap;
}

bool operator!=(const StrVec &s1, const StrVec &s2) {
    return !(s1 == s2);
}

bool operator==(const String &s1, const String &s2) {
    return s1.cStringBegin == s2.cStringBegin && s1.cStringEnd == s2.cStringEnd;
}

bool operator!=(const String &s1, const String &s2) {
    return !(s1 == s2);
}

int main() {
    return 0;
}