template <typename T, typename Args ... args>
auto my_make_shared(Args ... args) -> std::shared_ptr<T> {
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}
