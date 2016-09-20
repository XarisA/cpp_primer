#include <tuple>
#include <string>
#include <vector>
#include <utility>


int main() {
    std::tuple<int, int, int> t1{10, 20, 30};

    std::tuple<std::string, 
                std::vector<std::string>, 
                std::pair<std::string, int>> t2{
                    "this is a test",
                    {"this", "is", "a", "test"},
                    {"Five", 5}
                };
    
    return 0;
}