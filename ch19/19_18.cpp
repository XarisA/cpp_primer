#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
    std::vector<std::string> vec {"", "this", "", "is", "a", "test"};

    // std::function<bool (const std::string&)> fcn = &std::string::empty;

    // auto fcn = mem_fn(&std::string::empty);

    using std::placeholders::_1;
    auto fcn = std::bind(&std::string::empty, _1);
    
    auto cnt = 
        std::count_if(vec.cbegin(), vec.cend(), fcn);
    std::cout << cnt << std::endl;

    return 0;
}