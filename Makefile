# Add .d to Make's recognized suffixes.
SUFFIXES += .d

# Project directory
BUILD := build
TARGET := BattleP
LOADER := Loader

# Compiler definitions
CLANG := tool/win32/clang
CC := $(CLANG)
LD := $(DEVKITPPC)/bin/powerpc-eabi-ld
OBJCOPY := $(DEVKITPPC)/bin/powerpc-eabi-objcopy
ELF2REL := tool/win32/elf2rel.exe
LZX := tool/win32/lzx.exe

CFILES := $(wildcard src/*.c)
CPPFILES := $(wildcard src/*.cpp)
OFILES		:=	$(CPPFILES:.cpp=_cpp.o) $(CFILES:.c=_c.o)
OFILES		:= $(addprefix $(BUILD)/, $(OFILES))
DEPS	:= $(OFILES:.o=.d)

INCLUDE := include

LOADER_CPPFILES := loader/Loader.cpp
LOADER_OFILES		:= $(LOADER_CPPFILES:.cpp=_cpp.o)
LOADER_OFILES		:= $(addprefix $(BUILD)/, $(LOADER_OFILES))
LOADER_DEPS	:= $(LOADER_OFILES:.o=.d)



DUMMY != mkdir -p $(BUILD)/src $(BUILD)/loader

CFLAGS := --target=powerpc-gekko-ibm-kuribo-eabi -O3 -fno-rtti -fno-short-enums -fshort-wchar -fdeclspec -fno-exceptions -nodefaultlibs -ffreestanding -ffunction-sections -fdata-sections -Isrc -Isrc/platform -DLOADER_REL_LZ


default: $(BUILD)/$(TARGET).rel.LZ $(BUILD)/$(LOADER).bin

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
	@echo output ... $(TARGET).rel
	@$(ELF2REL) $(BUILD)/$(TARGET).elf $@

$(BUILD)/$(TARGET).rel.LZ: $(BUILD)/$(TARGET).rel
	@echo compress ... $(TARGET).rel.LZ
	@$(LZX) -ewb $< $@

$(BUILD)/$(LOADER).elf: $(LOADER_OFILES)
	@echo linking ... $(LOADER).elf
	@$(LD) -Tloader/Loader.ld --gc-sections -n -o $@ $<

$(BUILD)/$(LOADER).bin: $(BUILD)/$(LOADER).elf
	@echo output ... $(LOADER).bin
	@$(OBJCOPY) $< $@ -O binary
