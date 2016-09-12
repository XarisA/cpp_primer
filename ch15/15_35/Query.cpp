#include "Query.hpp"

Query operator~(const Query &q) {
    return ~q;
}

Query operator|(const Query &lhs, const Query &rhs) {
    return lhs | rhs;
}

Query operator&(const Query &lhs, const Query &rhs) {
    return lhs & rhs;
}