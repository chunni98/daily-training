TOP_DIR := $(shell pwd)
MAKE := make
CC := gcc
CFLAGS := -Wall -Werror -std=c11 -g -march=native
RM := rm -rf

export RM CC CFLAGS MAKE

.PHONY: clean check all leetcode clean

leetcode:
	$(MAKE) -C leetcode TOP_DIR:=$(TOP_DIR) all


clean:
	$(MAKE) -C leetcode clean
