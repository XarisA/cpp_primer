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
	return lhs.curr == rhs.curr;
}

template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("ptrs to different Blobs!");
	}
	return lhs.curr < rhs.curr;
}

template<typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;    
}
