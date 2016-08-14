#include <memory>
#include <iostream>

void process(std::shared_ptr<int> ptr) {
    std::cout << "preocess(): "<< ptr.use_count() << std::endl;
}

int main() {
    std::shared_ptr<int> p(new int(42)); 
    process(std::shared_ptr<int>(p));
    std::cout << "main(): "<< p.use_count() << std::endl;

    // ex 12.11 
    // error: pointer being freed was not allocated
    // p will be destroyed after the function call  
    process(std::shared_ptr<int>(p.get()));

    return 0;
}