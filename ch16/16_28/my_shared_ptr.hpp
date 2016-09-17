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
                                            { ++*ref_count; }

    operator bool() { return ptr ? true : false; }

    T& operator* () const { return *ptr; }
    T* operator->() const { return &*ptr; }

    auto use_count() const { return *ref_count; }
    auto get() const { return ptr; }
    auto unique() const { return *ref_count == 1; }
    auto swap(my_shared_ptr &p) { ::swap(*this, p); }

    void reset() { decrement_and_destroy(); }
    void reset(T* pointer) {
        if (ptr != pointer) {
            decrement_and_destroy();
            ptr = pointer;
            ref_count = new std::size_t(1);
        }
    }
    void reset(T *pointer, const std::function<void(T*)> &d) {
        reset(pointer);
        deleter = d;
    }

    my_shared_ptr(my_shared_ptr &&p) noexcept : 
    ptr(p.ptr), ref_count(p.ref_count), deleter(std::move(p.deleter)) {
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