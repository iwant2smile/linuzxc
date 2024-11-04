#include <iostream>
#include <fstream>
#include <cstdio>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./hacker-rm file-to-erase" << std::endl;
        return 1;
    }

    const char* filePath = argv[1];

    std::fstream file(filePath, std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error: Cannot open file '" << filePath << "'" << std::endl;
        return 1;
    }

    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();

    file.seekp(0, std::ios::beg);

    const std::streamsize bufferSize = 4096;
    char buffer[bufferSize] = {0};

    std::streampos totalBytesWritten = 0;
    while (totalBytesWritten < fileSize) {
        std::streamsize bytesToWrite = bufferSize;
        if (fileSize - totalBytesWritten < bufferSize) {
            bytesToWrite = fileSize - totalBytesWritten;
        }

        file.write(buffer, bytesToWrite);
        if (!file) {
            std::cerr << "Error: Failed to write to file '" << filePath << "'" << std::endl;
            file.close();
            return 1;
        }

        totalBytesWritten += bytesToWrite;
    }

    file.close();

    if (std::remove(filePath) != 0) {
        std::cerr << "Error: Cannot delete file '" << filePath << "'" << std::endl;
        return 1;
    }

    std::cout << "File '" << filePath << "' has been securely deleted." << std::endl;
    return 0;
}
