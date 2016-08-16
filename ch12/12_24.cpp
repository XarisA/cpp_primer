#include <iostream>
#include <cstring>

int main() {
    char c;
    std::size_t p = 0, arrSize = 16;
    char *cp = new char[arrSize];
    while (std::cin >> c) {
        if (p >= arrSize) {
            arrSize *= 2;
            char *temp = new char[arrSize];
            strcpy(temp, cp);
            delete [] cp;
            cp = temp;
        }
        cp[p++] = c;
    }
    printf("%s\n", cp);
    delete [] cp;

    return 0;
}