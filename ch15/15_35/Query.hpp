#ifndef QUERY
#define QUERY

#include "Query_base.hpp"
#include "WordQuery.hpp"
#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include <string>
#include <iostream>

class QueryResult;
class TextQuery;

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query) : q(query) { }
    std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}

inline Query::Query(const std::string &s) : q(new WordQuery(s)) { }

#endif