#include <string>

class isBigger {
public:
    isBigger(size_t s) : sz(s) {}
    bool operator()(const std::string &s) const { return s.size() >= sz; }
private:
    size_t sz;
};