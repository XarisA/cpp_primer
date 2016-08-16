#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

int main() {
    char *cp = new char[14];
    strcat(cp, "Hello, ");
    strcat(cp, "World!");
    printf("%s\n", cp);
    delete [] cp;

    std::string s1("Hello, "), s2("World!");
    std::cout << s1 + s2 << std::endl;
}