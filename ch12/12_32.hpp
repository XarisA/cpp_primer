#ifndef TEXT_QUERY
#define TEXT_QUERY

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using line_no = std::vector<std::string>::size_type;

class StrBlobPtr;

class StrBlob {
public:
    friend class StrBlobPtr;
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

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t sz, const std::string &msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if (sz >= ret->size()) {
            throw std::out_of_range(msg);
        }
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size()); 
}

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream &infile) : text() {
        std::string line, word;
        while (getline(infile, line)) {
            text.push_back(line);
            int n = text.size() - 1;
            std::istringstream iss(line);
            while (iss >> word) {
                auto &lines = lines_record[word];
                if (!lines) {
                    lines.reset(new std::set<line_no>);
                }
                lines->insert(n);
            }
        }
    }

    QueryResult query(const std::string&);
private:
    StrBlob text;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> lines_record;
};

class QueryResult {
friend std::ostream& print(std::ostream&, QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> w, StrBlob t)
                : word(s), lines(w), text(t) {}
    auto begin();
    auto end();
    auto get_file();
private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    StrBlob text;
};

QueryResult TextQuery::query(const std::string& word) {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = lines_record.find(word);
    if (loc == lines_record.end()) {
        return QueryResult(word, nodata, text);
    } 
    else {
        return QueryResult(word, loc->second, text);
    }
}

auto QueryResult::begin() {
    return lines->begin();
}
auto QueryResult::end() {
    return lines->end();
}
auto QueryResult::get_file() {
    return StrBlobPtr(text);
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, QueryResult &q) {
    os << q.word << " occurs " << q.lines->size() << " " << make_plural(q.lines->size(), "time") << std::endl;
    for (auto num : *q.lines) {
        StrBlobPtr p(q.text, num);
        os << "\t(line " << num + 1 << ") " << p.deref() << std::endl;
    }
    return os;
}

#endif