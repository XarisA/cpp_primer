#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    std::fstream file(argv[1], std::fstream::ate | std::fstream::in |
                                std::fstream::out);
    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return EXIT_FAILURE;
    }

    auto end_mark = file.tellg();
    file.seekg(0, std::fstream::beg);
    size_t cnt = 0;
    std::string line;

    while (file && file.tellg() != end_mark && getline(file, line)) {
        cnt += line.size() + 1;
        auto mark = file.tellg();
        file.seekp(0, std::fstream::end);
        file << cnt;
        if (mark != end_mark) file << " ";
        file.seekg(mark);
    }
    
    file.seekp(0, std::fstream::end);
    file << "\n";

    return 0;
}