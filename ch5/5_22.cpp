#include <cstdlib>

int get_size() {
    return (rand() % 100) - 50;     // return a random int in the range -50 to 49
}

int main() {
    int sz;
    do {
        sz = get_size();
    } while (sz <= 0);
    return 0;
}