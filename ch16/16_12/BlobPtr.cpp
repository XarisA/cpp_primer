#include "BlobPtr.hpp"

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {        // postfix
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {           // prefix
    ++curr;
    check(curr, "increment past end of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {        // postfix
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {           // prefix
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("ptrs to different Blobs!");
	}
	return lhs.i == rhs.i;
}

template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("ptrs to different Blobs!");
	}
	return lhs.i < rhs.i;
}