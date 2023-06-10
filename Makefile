CC = gcc
FLAGS = -Wall -Wextra -O2 -g
TARGET = bin/wmps
SOURCE_FILES = $(wildcard src/*.c)
OBJECT_FILES = $(patsubst src/%.c, src/%.o, $(SOURCE_FILES))

all: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	mkdir -p bin
	$(CC) $(FLAGS) $^ -o $@

src/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
