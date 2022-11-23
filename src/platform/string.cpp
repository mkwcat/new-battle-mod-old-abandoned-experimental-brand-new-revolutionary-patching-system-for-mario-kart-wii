#include "string.h"

EXTERN_TEXT(0x80005F34, void* memcpy(void* dst, const void* src, size_t len));
EXTERN_TEXT(0x80006038, void* memset(void* dst, int value, size_t len));
EXTERN_TEXT(0x80013120, char* strcpy(char* dst, const char* src));
EXTERN_TEXT(0x800135F0, char* strstr(const char* haystack, const char* needle));
EXTERN_TEXT(0x80021254, size_t strlen(const char* str));
