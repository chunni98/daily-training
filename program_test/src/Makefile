CC := gcc
CFLAGS = -Wall -g -O2 -I $(INCL_DIR)

SRCS := $(wildcard *.c)
OBJ_DIR := ../obj
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
INCL_DIR := ../incl
HEADERS := $(wildcard $(INCL_DIR)/*.h)

.PHONY : clean check all

all: $(OBJS)

$(OBJS) : $(OBJ_DIR)/%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

#$(OBJS) : %.o : %.c $(HEADERS)
#	$(CC) -o $@ $(CFLAGS) -c $<

check:
	@echo OBJS:
	@echo $(OBJS)
	@echo SRCS:
	@echo $(SRCS)

clean :
	rm -rf $(OBJS)
