#include "Query.hpp"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char **argv) {
    ifstream infile(argv[1]);
    TextQuery tq(infile);
    Query myQuery = Query("Knowing") & Query("best") | Query("hapless");
    cout << myQuery.rep() << endl;
    return 0;
}