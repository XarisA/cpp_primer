#include "Blob.hpp"

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> li) :
            data(std::make_shared<std::vector<T>>(li)) { }

template <typename T>
template <typename It>
    Blob<T>::Blob(It beg, It end) : data(std::make_shared<std::vector<T>>(beg, end)) { }

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}