#include "../ch12/12_19.hpp"

std::string& StrBlobPtr::operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

std::string* StrBlobPtr::operator->() const {
    return &this->operator*();
}

const std::string& ConstStrBlobPtr::operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

const std::string* ConstStrBlobPtr::operator->() const {
    return &this->operator*();
}

int main() {

}