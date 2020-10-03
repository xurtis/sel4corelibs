/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

/*
 * ISO/IEC 9899:2018 7.19 - Common definitions
 */

#pragma once

#define NULL ((void *)0)
#define offsetof(type, member) ((size_t)(&((type *)0)->member))

typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __SIZE_TYPE__    size_t;
/* we assume long long has the greatest alignment */
typedef long long        max_align_t;

/* We don't support wchar_t in libcore */
