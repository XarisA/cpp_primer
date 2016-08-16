#include <vector>
#include <string>
#include <memory>

class ConstStrBlobPtr;

class StrBlob {
public:
    friend class ConstStrBlobPtr;
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

    typedef std::vector<std::string>::size_type size_type;
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data-> empty(); }

    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back() { 
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    // element access
    std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const std::string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }
private:
    std::shared_ptr<std::vector<std::string>> data;
    
    // throws msg if data[i] isn't vaild
    void check(size_type i, const std::string &msg) const {
        if (i >= data->size()) throw std::out_of_range(msg);
    }
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    const std::string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr() {
        check(curr, "increment past end of ConstStrBlobPtr");
        ++curr;
        return *this;
    }
    bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t sz, const std::string &msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw std::runtime_error("unbound ConstStrBlobPtr");
        }
        if (sz >= ret->size()) {
            throw std::out_of_range(msg);
        }
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

int main() {
    const StrBlob sb;
    ConstStrBlobPtr csb(sb);

    return 0;
}