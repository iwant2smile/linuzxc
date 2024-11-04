#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./simple-copy source-file destination-file" << std::endl;
        return 1;
    }

    std::ifstream src(argv[1], std::ios::binary);
    if (!src) {
        std::cerr << "Error: Cannot open source file " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream dst(argv[2], std::ios::binary);
    if (!dst) {
        std::cerr << "Error: Cannot open destination file " << argv[2] << std::endl;
        return 1;
    }

    dst << src.rdbuf();

    std::cout << "File copied successfully." << std::endl;
    return 0;
}
