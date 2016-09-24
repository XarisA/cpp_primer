#include <iostream>

using namespace std;

int main() {
    cout << boolalpha << true << false << noboolalpha << true << false << endl;
    cout << hex << 0x1024 << " " << showbase << 0x1024 << noshowbase << endl;
    cout << dec << 10.0 << showpoint << " " << 10.0 << noshowpoint << endl;
    // TODO
    
    return 0;
}