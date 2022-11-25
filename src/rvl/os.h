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
    u32 sections;
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

bool OSLink(OSModuleInfo* info, void* bss);

void OSRegisterVersion(const char* string);

#ifdef __cplusplus
}
#endif
