CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = src/main.c src/log.c src/stats.c

OBJ = $(SRC:.c=.o)

TARGET = log_analyzer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)