# 目录树如下：
# .
# |--bin/
# |
# |--incl/
# |
# |--lib/
# |
# |--etc/
# |
# |--docs/
# |
# |--static/
# |   |---Makefile
# |
# |--dynamic/
# |   |---Makefile
# |
# |--obj/
# |   |---Makefile
# |
# |-src/
# |   |---Makefile
# |-Makefile
#
#
#
#

CROSS_COMPILE = # 交叉编译工具头,如：arm-linux-gnueabihf-
#
# 命令变量
AS := $(CROSS_COMPILE)as # 把汇编文件生成目标文件
LD := $(CROSS_COMPILE)ld # 链接器，为前面生成的目标代码分配地址空间，将多个目标文件链接成一个库或者一个可执行文件
CC := $(CROSS_COMPILE)gcc # 编译器，对 C 源文件进行编译处理，生成汇编文件
CPP := $(CC) -E
AR := $(CROSS_COMPILE)ar # 打包器，用于库操作，可以通过该工具从一个库中删除或则增加目标代码模块
NM := $(CROSS_COMPILE)nm # 查看静态库文件中的符号表
RM := rm -rf


STRIP       = $(CROSS_COMPILE)strip # 以最终生成的可执行文件或者库文件作为输入，然后消除掉其中的源码
OBJCOPY  = $(CROSS_COMPILE)objcopy # 复制一个目标文件的内容到另一个文件中，可用于不同源文件之间的格式转换
OBJDUMP = $(CROSS_COMPILE)objdump # 查看静态库或则动态库的签名方法

# 共享到 sub makefile
#
export AS LD CC CPP AR NM RM
export STRIP OBJCOPY OBJDUMP

# 目录变量
INCL_DIR :=
OBJ_DIR :=
SRC_DIR :=
BIN_DIR :=
LIBS_DIR :=


# 依赖 & 目标变量
OBJS :=
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)
SRCS :=
BIN :=
LIBS :=
TARGET := main

TOPDIR := $(shell pwd)

export TOPDIR

# 命令参数变量
DEFINES := -DNDEBUG
CFLAGS := -Wall -Werror -O2 -g $(DEFINES)
CFLAGS += -I $(shell pwd)/include
# LDFLAGS是告诉链接器从哪里寻找库文件，这在本Makefile是链接最后应用程序时的链接选项
LDFLAGS :=
ARFLAGS := rvs
SHARE := -fPIC -shared

export CFLAGS LDFLAGS

# 伪目标
# all 所有目标
# clean 清理可执行文件和 *.o
# dist 打包 ./src ./incl 目录为 tar.xz 压缩文件。
.PHONY : all clean dist

all : $(TARGET)

$(TARGET) :
	make -C ./src && make -C ./obj

dist :
	tar -I "xz -T0" -cvf $(TARGET).tar.xz ./src ./incl

clean :
	$(RM) $(OBJS)
	$(RM) $(TARGET)
