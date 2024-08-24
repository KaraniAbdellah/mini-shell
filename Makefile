CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = main
SRCS = main.c reading/read_tokenize.c processing/is_exit.c execution/execution_cmd/exec.c execution/built_in_cmd/built.c handling/handle.c

all: clean $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

