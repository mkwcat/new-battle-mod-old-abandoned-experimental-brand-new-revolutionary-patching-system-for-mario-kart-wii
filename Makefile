# Add .d to Make's recognized suffixes.
SUFFIXES += .d

# Project directory
BUILD := build
TARGET := mkwtm

# Compiler definitions
CLANG := tool/win32/clang
CC := $(CLANG)
LD := $(DEVKITPPC)/bin/powerpc-eabi-ld
ELF2REL := tool/win32/elf2rel.exe

CFILES := $(wildcard src/*.c)
CPPFILES := $(wildcard src/*.cpp)
INCLUDE := include

OFILES		:=	$(CPPFILES:.cpp=_cpp.o) $(CFILES:.c=_c.o)
OFILES		:= $(addprefix $(BUILD)/, $(OFILES))
DEPS	:= $(OFILES:.o=.d)

DUMMY != mkdir -p $(BUILD)/src

CFLAGS := --target=powerpc-gekko-ibm-kuribo-eabi -O3 -fno-rtti -fno-short-enums -fshort-wchar -fdeclspec -fno-exceptions -nodefaultlibs -ffreestanding -Isrc -Isrc/platform


default: $(BUILD)/$(TARGET).rel

clean:
	@echo cleaning...
	@rm -rf $(BUILD)

-include $(DEPS)

$(BUILD)/%_c.o: %.c
	@echo $<
	@$(CC) -MMD $(CFLAGS) -I../include -c -o $@ $<

$(BUILD)/%_cpp.o: %.cpp
	@echo $<
	@$(CC) -std=c++17 -MMD $(CFLAGS) -I../include -c -o $@ $<

$(BUILD)/$(TARGET).elf: $(OFILES)
	@echo linking ... $(TARGET).elf
	@$(LD) -Tlink.ld -r $(OFILES) -o $@

$(BUILD)/$(TARGET).rel: $(BUILD)/$(TARGET).elf
	@echo output ... $@
	$(ELF2REL) $(BUILD)/$(TARGET).elf $@
