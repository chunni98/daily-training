DIR_INCLUDES := include $(TOP_DIR)/include
DIR_SRC := src
DIR_OBJ := obj
DIR_BIN := bin
DIR_DEP := dep
DIR_LIB :=
DEFINES := -DNDEBUG


INCLUDES := $(foreach dir, $(DIR_INCLUDES), -I$(dir))  # 头文件目录(给每个文件目录添加前缀“-I”)
SRCS := $(wildcard $(DIR_SRC)/*.c)
OBJS := $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRCS))
DEPS := $(patsubst $(DIR_SRC)/%.c, $(DIR_DEP)/%.d, $(SRCS))
LIBS :=

#LIBS := -lm
LIBS :=

TARGET := $(DIR_BIN)/main

.PHONY: clean all check

ifeq ("$(MAKECMDGOALS)","all")
# MAKECMDGOALS表示当前make命令生成的目标，若执行命令为"make"或者“make all”则包含“-include $(DEPS)”
# 类似 C 语言中的include，将其他文件的内容原封不动的搬入当前文件。
# 若目标文件不存在，以文件名为目标查找规则，若找到，执行生成目标文件，再包含到Makefile。否则，产生错误，停止运行。
# 若目标文件存在，将目标文件包含进当前makefile。并以文件名为目标查找规则，若找到，比较依赖文件和目标文件的最新关系，决定是否执行命令；若没找到，无操作。
# 若目标文件存在，且目标文件名的规则找到并执行。Makefile会将最新生成的目标文件重新 include 进去。
-include $(DEPS)
endif

ifeq ("$(MAKECMDGOALS)","")
-include $(DEPS)
endif

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(LIBS)

$(OBJS): $(DIR_OBJ)/%.o : $(DIR_SRC)/%.c
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

# 如果没有 dep 文件夹，就创建 dep 文件夹
$(DIR_DEP):
	@mkdir $@


# set -e 脚本只要错误就中止执行
# sed命令：sed是一个流编辑器，用于流文本的修改（增/删/改/查)，sed的字符串替换方式为：sed 's,src des,g'，在sed中可以用正则表达式匹配替换目标。
# $$$$是一个特殊的Shell变量，用于生成唯一的临时文件名。
# 使用sed工具，将生成的依赖关系中的目标文件（.o文件）替换为当前目标文件（.d文件），并将结果写回.d文件中。
# 由于对seq.c和seq.h的修改需要更新seq.d的内容（因为依赖关系可能已变化），因此seq.d也要在依赖关系的目标列表中。
ifeq ("$(wildcard $(DIR_DEP))", "")
# 没有 dep 文件夹就创建
$(DIR_DEP)/%.d : $(DIR_SRC)/%.c $(DIR_DEP)
else
$(DIR_DEP)/%.d : $(DIR_SRC)/%.c
endif
	@echo "Creating $@ ..."
	@set -e;\
	$(CC) -MM $(INCLUDES) $< > $@.$$$$;\
	sed 's,\($*\)\.o[ :]*,$(DIR_OBJ)/\1.o $@ : ,g' < $@.$$$$ > $@;\
	@#$(RM) $@.$$$$

clean:
	-$(RM) $(OBJS)
	-$(RM) $(TARGET)
	-$(RM) $(DEPS)
