#ifndef WORDQUERY
#define WORDQUERY

#include "Query_base.hpp"
#include <string>

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) { }
    QueryResult eval(const TextQuery &t) const override {
        return t.query(query_word);
    }
    std::string rep() const override { return query_word; }
    std::string query_word;
};

#endif