#ifndef STR_BLOB
#define STR_BLOB

#include <vector>
#include <string>
#include <memory>

class StrBlobPtr;

class StrBlob {
public:
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);
    StrBlobPtr begin();
    StrBlobPtr end();

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

#endif

