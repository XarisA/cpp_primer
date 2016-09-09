#include "Bulk_quote.hpp"

int main() {
    Bulk_quote q1, q2;
    q1 = q2;
    Bulk_quote q3(q1);

    return 0;
}