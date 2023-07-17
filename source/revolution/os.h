#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSModuleInfo OSModuleInfo;

typedef struct OSModuleLink {
    OSModuleInfo* succ;
    OSModuleInfo* pred;
} OSModuleLink;

struct OSModuleInfo {
    u32 id;
    OSModuleLink head;
    u32 numSections;
    u32 sectionInfoOffset;
    u32 nameOffset;
    u32 nameLen;
    u32 version;
};

typedef struct {
    OSModuleInfo info;
    u32 bssSize;
    u32 relOffset;
    u32 impOffset;
    u32 impSize;
    u8 prologSection;
    u8 epilogSection;
    u8 unresolvedSection;
    u8 bssSection;
    u32 prolog;
    u32 epilog;
    u32 unresolved;
    u32 align;
    u32 bssAlign;
    u32 fixSize;
} OSModuleHeader;

typedef struct {
    u32 moduleId;
    u32 offset;
} OSModuleImp;

typedef struct {
    u32 offset;
    u32 length;
} OSModuleSectionInfo;

enum {
    R_PPC_NONE = 0,
    R_PPC_ADDR32 = 1,
    R_PPC_ADDR24 = 2,
    R_PPC_ADDR16 = 3,
    R_PPC_ADDR16_LO = 4,
    R_PPC_ADDR16_HI = 5,
    R_PPC_ADDR16_HA = 6,
    R_PPC_ADDR14 = 7,
    R_PPC_ADDR14_BRTAKEN = 8,
    R_PPC_ADDR14_BRNKTAKEN = 9,
    R_PPC_REL24 = 10,
    R_PPC_REL14 = 11,
    R_PPC_REL14_BRTAKEN = 12,
    R_PPC_REL14_BRNTAKEN = 13,
    R_RVL_NONE = 201,
    R_RVL_SECT = 202,
    R_RVL_STOP = 203,
};

typedef struct {
    u16 offset;
    u8 type;
    u8 section;
    u32 addend;
} OSModuleRelInfo;

bool OSLink(OSModuleInfo* info, void* bss);

void OSRegisterVersion(const char* string);

void OSReport(const char* format, ...);

EXTERN_TEXT_C(0x801A2660, //
  void OSPanic(const char* file, int line, const char* format, ...) //
);

#ifdef __cplusplus
}
#endif
