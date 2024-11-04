#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filepath>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd1 = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (fd1 < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int fd2 = dup(fd1);
    if (fd2 < 0) {
        perror("dup");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    const char *line1 = "first line\n";
    ssize_t bytes_written = write(fd1, line1, sizeof(char) * strlen(line1));
    if (bytes_written < 0) {
        perror("write");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    const char *line2 = "second line\n";
    bytes_written = write(fd2, line2, sizeof(char) * strlen(line2));
    if (bytes_written < 0) {
        perror("write");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    close(fd1);
    close(fd2);

    return 0;
}
