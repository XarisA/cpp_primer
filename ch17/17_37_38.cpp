#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    std::ifstream file(argv[1]);
    char line[30];
    while (file.getline(line, 30, ' ')) {   
        // print each word onto its own line by adding a whitespace delimiter
        std::cout << line << std::endl;
    }
    return 0;
}