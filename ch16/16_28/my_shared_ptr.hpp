#ifndef MY_SHARED_PTR
#define MY_SHARED_PTR

#include <functional>

template <typename T> class my_shared_ptr;

template <typename T>
void swap(my_shared_ptr<T> &p1, my_shared_ptr<T> &p2);

template <typename T>
class my_shared_ptr {
    friend void swap<T>(my_shared_ptr<T> &p1, my_shared_ptr<T> &p2);
public:
    my_shared_ptr() : ptr(nullptr), 
                    ref_count(new size_t(1)), 
                    deleter(std::default_delete<T>()) { } 
    my_shared_ptr(T *p) : ptr(p),
                        ref_count(new size_t(1)),
                        deleter(std::default_delete<T>()) { }
    my_shared_ptr(const my_shared_ptr &p) : ptr(p.ptr),
                                            ref_count(p.ref_count),
                                            deleter(p.deleter) 
    {
        ++*ref_count;    
    }

    my_shared_ptr(my_shared_ptr &&p) noexcept : 
    ptr(p.ptr), ref_count(p.ref_count), deleter(std::move(p.deleter)) 
    {
        p.ptr = nullptr;
        p.ref_count = nullptr;
    }

    ~my_shared_ptr();
private:
    size_t *ref_count;
    std::function<void(T*)> deleter;
    T *ptr;

    void decrement_and_destroy() {
        if (ptr && --*ref_count == 0) {
            delete ref_count;
            deleter(ptr);
        }
        else if (!ptr) {
            delete ref_count;
        }
        ref_count = nullptr;
        ptr = nullptr;
    }
};

template <typename T>
void swap(my_shared_ptr<T> &p1, my_shared_ptr<T> &p2) {
    using std::swap;
    swap(p1.ptr, p2.ptr);
    swap(p1.ref_count, p2.ref_count);
    swap(p1.deleter, p2.deleter);
}

#endif