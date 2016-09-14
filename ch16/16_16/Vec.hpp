#ifndef VEC
#define VEC

#include <initializer_list>
#include <utility>
#include <memory>

template <typename T> class Vec;

template <typename T>
bool operator==(const Vec<T>&, const Vec<T>&);

template <typename T>
bool operator!=(const Vec<T>&, const Vec<T>&);

template <typename T>
bool operator>=(const Vec<T>&, const Vec<T>&);

template <typename T>
bool operator<=(const Vec<T>&, const Vec<T>&);

template <typename T>
bool operator>(const Vec<T>&, const Vec<T>&);

template <typename T>
bool operator<(const Vec<T>&, const Vec<T>&);

template <typename T>
class Vec {
    friend bool operator== <T>(const Vec<T>&, const Vec<T>&);
    friend bool operator!= <T>(const Vec<T>&, const Vec<T>&);
    friend bool operator< <T>(const Vec<T>&, const Vec<T>&);
    friend bool operator> <T>(const Vec<T>&, const Vec<T>&);
    friend bool operator<= <T>(const Vec<T>&, const Vec<T>&);
    friend bool operator>= <T>(const Vec<T>&, const Vec<T>&);
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) { };
    Vec(const Vec&);
    Vec(std::initializer_list<T>);

    Vec& operator=(const Vec&);
    Vec& operator=(std::initializer_list<T>);
    Vec& operator[](size_t);
    const Vec& operator[](size_t) const;

    T* begin() const { return elements; }
    T* end() const { return first_free; }
    const T* cbegin() const { return elements; }
    const T* cend() const { return first_free; }

    void push_back(const T&);
    void reserve(const size_t);
    void resize(const size_t);
    void resize(const size_t, const T&);

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    ~Vec() { free(); }
private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void alloc_n_move(size_t);
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

#endif