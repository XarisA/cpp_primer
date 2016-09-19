#include "Vec.hpp"
#include <algorithm>

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
    return lhs.size() == rhs.size() &&
            std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin());
}

template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs < rhs);
}

template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs > rhs);
}

template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
    return std::lexicographical_compare(rhs.cbegin(), rhs.cend(),
                                        lhs.cbegin(), lhs.cend());
}

template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
    return std::lexicographical_compare(lhs.cbegin(), lhs.cend(),
                                        rhs.cbegin(), rhs.cend());
}

template <typename T>
Vec<T>::Vec(const Vec<T> &v) {
    auto data = alloc_n_copy(v.begin(), v.end());
    elements = data.first;
    cap = first_free = data.second;
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> li) {
    auto data = alloc_n_copy(li.begin(), li.end());
    elements = data.first;
    cap = first_free = data.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &v) {
    auto data = alloc_n_copy(v.begin(), v.end());
    free();
    elements = data.first;
    cap = first_free = data.second;
    return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> li) {
    auto data = alloc_n_copy(li.begin(), li.end());
    free();
    elements = data.first;
    cap = first_free = data.second;
    return *this;
}

template <typename T>
T& Vec<T>::operator[](size_t idx) {
    return *(elements + idx);
}

template <typename T>
const T& Vec<T>::operator[](size_t idx) const {
    return *(elements + idx);
}

template <typename T>
void Vec<T>::push_back(const T &t) {
    chk_n_alloc();
    alloc.construct(first_free++, t);
}

template <typename T>
void Vec<T>::reserve(const size_t n) {
    if (cap >= n) return;
    alloc_n_move(n);
}

template <typename T>
void Vec<T>::resize(const size_t n) {
    resize(n, T());
}

template <typename T>
void Vec<T>::resize(const size_t n, const T &t) {
    if (n > size()) {
        if (n > capacity()) reserve(n * 2);
        for (auto i = size(); i != n; ++i) {
            alloc.construct(first_free++, t);
        }
    }
    else if (n < size()) {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
}

template <typename T>
void Vec<T>::alloc_n_move(size_t n) {
    auto data = alloc.allocate(n);
    auto dest = data;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = data;
    first_free = dest;
    cap = elements + n;
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *beg, const T *end) {
    auto data = alloc.allocate(end - beg);
    return {data, uninitialized_copy(beg, end, data)};
}

template <typename T>
void Vec<T>::free() {
    if (elements) {
        std::for_each(elements, first_free, 
            [this](const T &rhs){alloc.destroy(&rhs);});
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
void Vec<T>::reallocate() {
    auto new_size = size() ? size() * 2 : 1;
    alloc_n_move(new_size);
}

template <typename T>
template <class ... Args>
inline void Vec<T>::emplace_back(Args&&... args) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}