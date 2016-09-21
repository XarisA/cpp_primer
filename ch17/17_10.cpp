#include <bitset>
#include <iostream>

int main() {
    std::bitset<32> bs;
    int sequence[] = {1, 2, 3, 4, 8, 13, 21};
    for (auto i : sequence)
        bs.set(i);
    
    std::bitset<32> bs2;
    bs2 = bs;

    std::cout << bs.to_string() << std::endl;
    std::cout << bs2.to_string() << std::endl;
    return 0;
}