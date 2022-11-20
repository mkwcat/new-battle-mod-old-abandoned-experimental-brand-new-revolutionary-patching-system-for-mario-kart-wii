#pragma once

// Type definitions
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef float f32;
typedef double f64;

// ASM definitions
#define r0 % r0
#define r1 % r1
#define sp % r1
#define r2 % r2
#define toc % r2
#define r3 % r3
#define r4 % r4
#define r5 % r5
#define r6 % r6
#define r7 % r7
#define r8 % r8
#define r9 % r9
#define r10 % r10
#define r11 % r11
#define r12 % r12
#define r13 % r13
#define r14 % r14
#define r15 % r15
#define r16 % r16
#define r17 % r17
#define r18 % r18
#define r19 % r19
#define r20 % r20
#define r21 % r21
#define r22 % r22
#define r23 % r23
#define r24 % r24
#define r25 % r25
#define r26 % r26
#define r27 % r27
#define r28 % r28
#define r29 % r29
#define r30 % r30
#define r31 % r31

#define ASM(...) asm(#__VA_ARGS__)

#define ASM_FUNCTION(_PROTOTYPE, ...)                                          \
  __attribute__((naked)) _PROTOTYPE                                            \
  {                                                                            \
    ASM(__VA_ARGS__);                                                          \
  }

typedef struct {
    unsigned int* addr;
    unsigned int* dest;
} __replace_struct;

#define REPLACE(addr, prototype)                                               \
  extern unsigned int ext_##addr;                                              \
  extern unsigned int replaced_func_##addr;                                    \
  __attribute__((section(".replarray")))                                       \
  __replace_struct replstruct_##addr = {&ext_##addr, &replaced_func_##addr};   \
  asm(".section .replaced." #addr "\n"                                         \
      ".global replaced_func_" #addr "\n"                                      \
      ".p2align 2\n"                                                           \
      "replaced_func_" #addr ":\n");                                           \
  __attribute__((section(".replaced." #addr))) prototype

#define REPLACE_ASM(addr, prototype, ...)                                      \
  extern unsigned int ext_##addr;                                              \
  extern unsigned int replaced_func_##addr;                                    \
  __attribute__((section(".replarray")))                                       \
  __replace_struct replstruct_##addr = {&ext_##addr, &replaced_func_##addr};   \
  asm(".section .replaced." #addr "\n"                                         \
      ".global replaced_func_" #addr "\n"                                      \
      ".p2align 2\n"                                                           \
      "replaced_func_" #addr ":\n");                                           \
  __attribute__((section(".replaced." #addr))) __attribute__((naked))          \
  prototype                                                                    \
  {                                                                            \
    ASM(__VA_ARGS__);                                                          \
  }
#define EXTERN_TEXT(addr, prototype)                                           \
  _Pragma("GCC diagnostic push")                                               \
    _Pragma("GCC diagnostic ignored \"-Wreturn-type\"")                        \
      __attribute__((section(".external." #addr))) __attribute__((weak))       \
      prototype                                                                \
  {                                                                            \
  }                                                                            \
  _Pragma("GCC diagnostic pop")

#define EXTERN_TEXT_C(addr, prototype)                                         \
  _Pragma("GCC diagnostic push")                                               \
    _Pragma("GCC diagnostic ignored \"-Wreturn-type\"")                        \
      __attribute__((section(".external." #addr)))                             \
      __attribute__((weak)) extern "C" prototype                               \
  {                                                                            \
  }                                                                            \
  _Pragma("GCC diagnostic pop")

#define EXTERN_DATA(addr, prototype)                                           \
  __attribute__((section(".external." #addr))) prototype

enum class Region {
    P = 0x54A9,
    E = 0x5409,
    J = 0x53CD,
    K = 0x5511,
};

static inline Region GetCodeRegion()
{
    return Region(*(u16*) 0x8000620A);
}
