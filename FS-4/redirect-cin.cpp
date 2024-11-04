#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>

void initialize(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No file path provided." << std::endl;
        exit(1);
    }

    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(1);
    }

    if (dup2(file_descriptor, STDIN_FILENO) == -1) {
        std::cerr << "Error: Unable to redirect standard input." << std::endl;
        close(file_descriptor);
        exit(1);
    }

    close(file_descriptor);
}

int main(int argc, char** argv) {
    initialize(argc, argv);

    std::string input;
    std::cin >> input;

    std::string reversed(input.rbegin(), input.rend());

    std::cout << reversed << std::endl;

    return 0;
}
