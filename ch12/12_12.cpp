#include <memory>
#include <iostream>

void process(std::shared_ptr<int> ptr) {
    std::cout << "preocess(): "<< ptr.use_count() << std::endl;
}

int main() {
    auto p = new int();
    auto sp = std::make_shared<int>();

    process(sp);
    //process(new int());       // no matching
    //process(p);               // no matching
    process(std::shared_ptr<int>(p));
    std::cout << sp.use_count() << std::endl;

    return 0;
}