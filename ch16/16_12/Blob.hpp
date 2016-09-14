#ifndef BLOB
#define BLOB

#include <vector>
#include <string>

template <typename T> class BlobPtr;

template <typename T> class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();

    T& front();
    T& back();
    T& operator[](size_type i);
    const T& operator[](size_type i) const;
private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_type i, const std::string &msg) const;
};

#endif