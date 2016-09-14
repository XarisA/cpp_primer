#ifndef BLOB_PTR
#define BLOB_PTR

#include "Blob.hpp"

template <typename> class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T> class Blob;

template <typename T> class BlobPtr {
public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    T& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<T>> 
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

#endif