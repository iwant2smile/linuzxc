CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
TARGET = manual-append

all: $(TARGET)

$(TARGET): manual-append.c
	$(CC) $(CFLAGS) -o $(TARGET) manual-append.c

clean:
	rm -f $(TARGET) result.txt
