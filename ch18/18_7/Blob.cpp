#include "Blob.hpp"

template <typename T>
Blob<T>::Blob() try : data(std::make_shared<std::vector<T>>()) { }
                catch (const std::bad_alloc &e) { /* handle out of memory */ }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> li) try :
            data(std::make_shared<std::vector<T>>(li)) { }
            catch (const std::bac_alloc &e) { /* handle out of memory */ }

template <typename T>
template <typename It>
    Blob(It beg, It end) try : data(std::make_shared<std::vector<T>>(beg, end))
                            { } catch (const std::bad_alloc &e)
                            { /* handle out of memory */ };

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