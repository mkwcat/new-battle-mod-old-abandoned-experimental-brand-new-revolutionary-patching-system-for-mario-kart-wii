# Add .d to Make's recognized suffixes.
SUFFIXES += .d

# Project directory
BUILD := build
ARCHIVE := MKWBattleModData
DVDDATA := $(BUILD)/$(ARCHIVE).arc.d
DVDDATA_SRC := assets/dvddata
TARGET := BattleP
LOADER := Loader


# Compiler definitions
CLANG := tool/win32/clang
CC := $(CLANG)
LD := $(DEVKITPPC)/bin/powerpc-eabi-ld
OBJCOPY := $(DEVKITPPC)/bin/powerpc-eabi-objcopy
ELF2REL := tool/win32/elf2rel.exe
LZX := tool/win32/lzx.exe

CFILES := $(wildcard source/*.c)
CPPFILES := $(wildcard source/*.cpp)
OFILES		:=	$(CPPFILES:.cpp=_cpp.o) $(CFILES:.c=_c.o)
OFILES		:= $(addprefix $(BUILD)/, $(OFILES))
DEPS	:= $(OFILES:.o=.d)

INCLUDE := include

LOADER_CPPFILES := loader/Loader.cpp
LOADER_OFILES		:= $(LOADER_CPPFILES:.cpp=_cpp.o)
LOADER_OFILES		:= $(addprefix $(BUILD)/, $(LOADER_OFILES))
LOADER_DEPS	:= $(LOADER_OFILES:.o=.d)

DUMMY != mkdir -p $(BUILD)/source $(BUILD)/loader $(DVDDATA)

CFLAGS := --target=powerpc-gekko-ibm-kuribo-eabi -O3 -fno-rtti -fno-short-enums -fshort-wchar -fdeclspec -fno-exceptions -nodefaultlibs -ffreestanding -ffunction-sections -fdata-sections -Isource -Isource/platform -Isource/game -DLOADER_REL_LZ


default: $(BUILD)/$(ARCHIVE).arc $(BUILD)/$(LOADER).bin

clean:
	@echo cleaning...
	@rm -rf $(BUILD)

-include $(DEPS)


DVD_DIRS := \
$(DVDDATA)/Boot \
$(DVDDATA)/Boot/Strap \
$(DVDDATA)/Boot/Strap/cn \
$(DVDDATA)/Boot/Strap/eu \
$(DVDDATA)/Boot/Strap/jp \
$(DVDDATA)/Boot/Strap/kr \
$(DVDDATA)/Boot/Strap/us \
$(DVDDATA)/contents \
$(DVDDATA)/debug \
$(DVDDATA)/Demo \
$(DVDDATA)/Demo/Trophy \
$(DVDDATA)/hbm \
$(DVDDATA)/Race \
$(DVDDATA)/Race/Competition \
$(DVDDATA)/Race/Competition/CommonObj \
$(DVDDATA)/Race/Course \
$(DVDDATA)/Race/Course/Object \
$(DVDDATA)/Race/Kart \
$(DVDDATA)/Race/MissionRun \
$(DVDDATA)/Race/TimeAttack \
$(DVDDATA)/Race/TimeAttack/ghost1 \
$(DVDDATA)/Race/TimeAttack/ghost2 \
$(DVDDATA)/rel \
$(DVDDATA)/Scene \
$(DVDDATA)/Scene/Model \
$(DVDDATA)/Scene/Model/Kart \
$(DVDDATA)/Scene/UI \
$(DVDDATA)/sound \
$(DVDDATA)/sound/strm \
$(DVDDATA)/thp \
$(DVDDATA)/thp/battle \
$(DVDDATA)/thp/button \
$(DVDDATA)/thp/course \
$(DVDDATA)/thp/ending \
$(DVDDATA)/thp/title

DUMMY != mkdir -p $(DVDDATA) $(DVD_DIRS)

DVD_FILES := \
$(DVDDATA)/Boot/WiimmfiP.bin \
$(DVDDATA)/Race/Common.szs \
$(DVDDATA)/rel/BattleP.rel.LZ

$(DVDDATA)/%:
	@cp -r $(DVDDATA_SRC)/* $(DVDDATA)

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

$(DVDDATA)/rel/$(TARGET).rel.LZ: $(BUILD)/$(TARGET).rel
	@echo compress ... $(TARGET).rel.LZ
	@$(LZX) -ewb $< $@

$(BUILD)/$(LOADER).elf: $(LOADER_OFILES)
	@echo linking ... $(LOADER).elf
	@$(LD) -Tloader/Loader.ld --gc-sections -n -o $@ $<

$(BUILD)/$(LOADER).bin: $(BUILD)/$(LOADER).elf
	@echo output ... $(LOADER).bin
	@$(OBJCOPY) $< $@ -O binary

$(BUILD)/$(ARCHIVE).arc: $(DVD_FILES)
	@echo Building Archive...
	@python tool/python/wuj5/wuj5.py encode $(BUILD)/$(ARCHIVE).arc.d
