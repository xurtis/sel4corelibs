/*
 * These are a set of static checks to ensure the types we are using
 * have their expected size.
 */

#pragma once

/*
 * Fixed-width types.
 */
_Static_assert(sizeof(char)      == 1, "char is one bytes / 8 bits");
_Static_assert(sizeof(short)     == 2, "short is 2 bytes / 16 bits");
_Static_assert(sizeof(int)       == 4, "int is 4 bytes / 32 bits");
_Static_assert(sizeof(long long) == 8, "long long is 8 bytes / 64 bits");

#define CORE_U8  unsigned char
#define CORE_U16 unsigned short
#define CORE_U32 unsigned int
#define CORE_U64 unsigned long long
#define CORE_S8  signed char
#define CORE_S16 signed short
#define CORE_S32 signed int
#define CORE_S64 signed long long

#define CORE_UNSIGNED_MIN 0x0u
#define CORE_U8_MAX       0xFFu
#define CORE_U16_MAX      0xFFFFu
#define CORE_U32_MAX      0xFFFFFFFFu
#define CORE_U64_MAX      0xFFFFFFFFFFFFFFFFull

/* All arithemtic and constants for sizes smaller than an int are
 * performed as int expressions. */

#define CORE_S8_MIN       0xFFFFFF80
#define CORE_S8_MAX       0x0000007F
#define CORE_S16_MIN      0xFFFF8000
#define CORE_S16_MAX      0x00007FFF
#define CORE_S32_MIN      0x80000000
#define CORE_S32_MAX      0x7FFFFFFF
#define CORE_S64_MIN      0x8000000000000000ll
#define CORE_S64_MAX      0x7FFFFFFFFFFFFFFFll

/*
 * Word-width types.
 */
_Static_assert(sizeof(long) == sizeof(void *), "long is word sized")

#define CORE_UWORD unsigned long
#define CORE_SWORD signed long
