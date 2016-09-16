#ifndef MY_UNIQUE_PTR
#define MY_UNIQUE_PTR

#include <memory>

template <typename T, typename D> class my_unique_ptr;

template <typename T, typename D>
void swap(my_unique_ptr<T, D> &lhs, my_unique_ptr<T, D> &rhs);

template <typename T, typename D = std::default_delete<T>>
class my_unique_ptr {
    friend void swap<T, D>(my_unique_ptr<T, D> &lhs, my_unique_ptr<T, D> &rhs);
public:
    my_unique_ptr() = default;
    explicit my_unique_ptr(T *t) : ptr(t) { }

    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    my_unique_ptr(const my_unique_ptr &&p) noexcept 
                    : ptr(p.ptr)  { p.ptr = nullptr; } 
    my_unique_ptr& operator=(const my_unique_ptr&&) noexcept;

    void swap(my_unique_ptr &p) { ::swap(*this, p); }

    T& operator*() const   { return *ptr; }
    T* operator->() const   { return & this->operator*(); }
    operator bool() const   { return ptr ? true : false; }

    void reset() noexcept { deleter(ptr); ptr = nullptr; }
    void reset(T* p) noexcept { deleter(ptr); ptr = p; }

    T* release();

    ~my_unique_ptr() { deleter(ptr); }
private:
    T *ptr = nullptr;
    D deleter = D();
};

template <typename T, typename D>
void swap(my_unique_ptr<T, D> &lhs, my_unique_ptr<T, D> &rhs) {
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.deleter, rhs.deleter);
}

template<typename T, typename D>
inline my_unique_ptr<T, D>&
my_unique_ptr<T, D>::operator=(const my_unique_ptr &&rhs) noexcept
{
    if(this->ptr != rhs.ptr)
    {
        deleter(ptr);
        ptr = nullptr;
        ::swap(*this, rhs);
    }
    return *this;
}

template<typename T, typename D>
inline T* my_unique_ptr<T, D>::release()
{
    T* ret = ptr;
    ptr = nullptr;
    return ret;
}

#endif