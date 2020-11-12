# 目标名称
TARGET=hello_main

# 架构检查
ARCH?=x86
$(info ARCH=$(ARCH))
ifeq ($(ARCH), x86)
CC=gcc
else
$(error ARCH--$(ARCH) isn't support)
endif

# 过程文件目录
BUILD_DIR=build_$(ARCH)
${info BUILD_DIR: $(BUILD_DIR)}

# 获得源文件及中间文件
SRC_DIR=src
TEST_SRC_DIR=src/test

SRCS=${wildcard $(SRC_DIR)/*.c $(TEST_SRC_DIR)/*.c}
${info SRCS: $(SRCS)}

OBJECT=${patsubst %.c, %.o, $(SRCS)}
${info OBJECT: $(OBJECT)}


INC_DIR =inc
DEPS=${wildcard $(INC_DIR)/*.h}
${info deps list: $(DEPS)}

CFLAGS = $(patsubst %, -I%, $(INC_DIR))
${info cflags list: $(CFLAGS)}
######################################################


all: CHECKDIR $(BUILD_DIR)/$(TARGET)

CHECKDIR:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(OBJECT)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJECT):%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#伪目标
.PHONY: clean cleanall

#按架构删除
clean:
	rm -rf $(OBJECT) $(BUILD_DIR)/$(TARGET)
#全部删除
cleanall:
	rm -rf build_x86 build_arm