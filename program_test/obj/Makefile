CC := gcc

OBJS := $(wildcard *.o)
TARGET_DIR := ../bin
TARGET := $(TARGET_DIR)/main

.PHONY : clean check all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^


check:

clean :
	rm -rf $(TARGET)
