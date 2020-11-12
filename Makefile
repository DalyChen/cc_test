#定义变量
TARGET=hello_main

ARCH?=x86
$(info ARCH=$(ARCH))

ifeq ($(ARCH), x86)
CC=gcc
else
$(error ARCH--$(ARCH) isn't support)
endif

BUILD_DIR=build_$(ARCH)
${info BUILD_DIR: $(BUILD_DIR)}

#存放源文件的文件夹
SRC_DIR=src
#存放头文件的文件夹
INC_DIR =inc

SRCS=${wildcard $(SRC_DIR)/*.c}
${info files list: $(SRCS)}

OBJSLIST=${patsubst %.c, $(BUILD_DIR)/%.o, ${notdir $(SRCS)}}
${info objs list: $(OBJSLIST)}

DEPS=${wildcard $(INC_DIR)/*.h}
${info deps list: $(DEPS)}

CFLAGS = $(patsubst %, -I%, $(INC_DIR))
${info cflags list: $(CFLAGS)}


$(BUILD_DIR)/$(TARGET): $(OBJSLIST)
	@mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^ $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

#伪目标
.PHONY: clean cleanall

#按架构删除
clean:
	rm -rf $(BUILD_DIR)
#全部删除
cleanall:
	rm -rf build_x86 build_arm