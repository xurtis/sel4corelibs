/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

/*
 * ISO/IEC 9899:2018 7.24 - String handling
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

/* 7.24.2 - Copying functions */

static inline void *memcpy(
	void *restrict s1,
	const void *restrict s2,
	size_t n
) {
	return __builtin_memcpy(s1, s2, n)
}

/* GCC doesn't have a memmove builtin */
static inline void *memmove(void *s1, const void *s2, size_t n)
{
	unsigned char *c1 = s1;
	unsigned char *c2 = s2;

	if ((uintptr_t)c1 <= (uintptr_t)c2) {
		/* c1 starts before the start of c2 */
		while (n > 0) {
			*c1 = *c2;
			c1 += 1;
			c2 += 1;
			n -= 1;
		}
	} else {
		/* c1 starts after the start of c2, so go backwards */
		c1 += n;
		c2 += n;
		while (n > 0) {
			c1 -= 1;
			c2 -= 1;
			*c1 = *c2;
			n -= 1;
		}
	}
}

static inline char *strcpy(char *restrict s1, const char *restrict s2)
{
	return __builtin_strcpy(s1, s2);
}

static inline char *strncpy(
	char *restrict s1,
	const char *restrict s2,
	size_t n
) {
	return __builtin_strncpy(s1, s2, n);
}

/* 7.24.3 - Concatenation functions */

static inline char *strcat(char *restrict s1, const char *restrict s2)
{
	return __builtin_strcat(s1, s2);
}

static inline char *strncat(
	char *restrict s1,
	const char *restrict s2,
	size_t n
) {
	return __builtin_strncat(s1, s2, n);
}

/* 7.24.4 - Comparison functions */

static inline int memcmp(const void *s1, const void *s2, size_t n)
{
	return __builtin_memcmp(s1, s2, n);
}

static inline int strcmp(const void *s1, const void *s2)
{
	return __builtin_strcmp(s1, s2);
}

static inline int strncmp(const void *s1, const void *s2, size_t n)
{
	return __builtin_strncmp(s1, s2, n);
}

/* We don't support locales, so no strcoll or strxfrm here */

/* 7.24.5 - Search functions */

static inline void *memchr(const void *s, int c, size_t n)
{
	return __builtin_memchr(s, c, n);
}

static inline char *strchr(const char *s, int c)
{
	return __builtin_strchr(s, c);
}

static inline size_t strcspn(const char *s1, const char *s2)
{
	return __builtin_strcspn(s1, s2);
}

static inline char *strpbrk(const char *s1, const char *s2)
{
	return __builtin_strpbrk(s1, s2);
}

static inline char *strrchr(const char *s, int c)
{
	return __builtin_strrchr(s, c);
}

static inline size_t strspn(const char *s1, const char s2)
{
	return __builtin_strspn(s1, s2);
}

static inline char *strstr(const char *s1, const char *s2)
{
	return __builtin_strstr(s1, s2);
}

/* We don't support strtok as it is not re-entrant */

/* 7.24.6 - Miscellaneous functions */

static inline void *memset(void *s, int c, size_t n)
{
	return __builtin_memset(s, c, n);
}

static inline size_t strlen(const char *s)
{
	return __builtin_strlen(s);
}

/* We don't support errno so no strerror here */
