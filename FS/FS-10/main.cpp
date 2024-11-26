#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char* argv[]) {
    
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <source-file> <destination-file>\n";
        return 1;
    }

    const char* source = argv[1];
    const char* destination = argv[2];

    
    int sourceFd = open(source, O_RDONLY);
    if (sourceFd == -1) {
        std::cerr << "Error opening source file: " << strerror(errno) << "\n";
        return errno;
    }

    
    int destinationFd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (destinationFd == -1) {
        std::cerr << "Error opening destination file: " << strerror(errno) << "\n";
        close(sourceFd);
        return errno;
    }

    
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    ssize_t bytesWritten;
    off_t totalBytes = 0;
    off_t totalData = 0;
    off_t totalHoles = 0;

    
    while ((bytesRead = read(sourceFd, buffer, BUFFER_SIZE)) > 0) {
        size_t offset = 0;

        while (offset < (size_t)bytesRead) {
            if (buffer[offset] == '\0') {
                
                off_t holeSize = 1;

                
                while (offset + holeSize < (size_t)bytesRead && buffer[offset + holeSize] == '\0') {
                    holeSize++;
                }

                
                if (lseek(destinationFd, holeSize, SEEK_CUR) == -1) {
                    std::cerr << "Error seeking in destination file: " << strerror(errno) << "\n";
                    close(sourceFd);
                    close(destinationFd);
                    return errno;
                }

                totalHoles += holeSize;
                offset += holeSize;
            } else {
                
                size_t dataSize = 1;

                
                while (offset + dataSize < (size_t)bytesRead && buffer[offset + dataSize] != '\0') {
                    dataSize++;
                }

                bytesWritten = write(destinationFd, buffer + offset, dataSize);
                if (bytesWritten == -1) {
                    std::cerr << "Error writing to destination file: " << strerror(errno) << "\n";
                    close(sourceFd);
                    close(destinationFd);
                    return errno;
                }

                totalData += bytesWritten;
                offset += dataSize;
            }
        }

        totalBytes += bytesRead;
    }

    
    if (bytesRead == -1) {
        std::cerr << "Error reading source file: " << strerror(errno) << "\n";
        close(sourceFd);
        close(destinationFd);
        return errno;
    }

    
    close(sourceFd);
    close(destinationFd);

    
    std::cout << "Successfully copied " << totalBytes
              << " bytes (data: " << totalData << ", hole: " << totalHoles << ").\n";

    return 0;
}
