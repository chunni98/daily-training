CC := g++
INCLUDE_PATH := ./include ../include
HEADERS := $(foreach path, $(INCLUDE_PATH), $(wildcard $(path)/*.h))
SRCS := $(wildcard ./src/*.cc)
OBJS := $(patsubst ./src/%.cc, ./obj/%.o, $(SRCS))
INCLUDE := $(foreach path, $(INCLUDE_PATH), -I$(path))
CFLAGS := -Wall -std=gnu++14
TARGET := ./bin/main

.Phony: all clean check run


all: $(TARGET)

check:
	@echo $(OBJS)
	@echo $(HEADERS)

$(TARGET) : $(OBJS)
	g++ -o $@ $^

$(OBJS) : ./obj/%.o: ./src/%.cc $(HEADERS)
	$(CC) -o $@ $(CFLAGS) $(INCLUDE) -c $<

run:
	@./bin/main.exe

clean:
	@del bin\main.exe
	@del obj\*.o
