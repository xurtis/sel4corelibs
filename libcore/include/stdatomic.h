/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

/*
 * ISO/IEC 9899:2018 7.17 - Atomics
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* We don't assume statically that any type is lock-free */
#define ATOMIC_BOOL_LOCK_FREE      0
#define ATOMIC_CHAR_LOCK_FREE      0
/* We don't support char16_t, char32_t, or wchar_t in libcore */
#define ATOMIC_SHORT_LOCK_FREE     0
#define ATOMIC_INT_LOCK_FREE       0
#define ATOMIC_LONG_LOCK_FREE      0
#define ATOMIC_LLONG_LOCK_FREE     0
#define ATOMIC_POINTER_LOCK_FREE   0

typedef enum {
	memory_order_relaxed = __ATOMIC_RELAXED,
	memory_order_consume = __ATOMIC_CONSUME,
	memory_order_acquire = __ATOMIC_ACQUIRE,
	memory_order_release = __ATOMIC_RELEASE,
	memory_order_acq_rel = __ATOMIC_ACQ_REL,
	memory_order_seq_cst = __ATOMIC_SEQ_CST,
} memory order;

typedef struct {
	char byte;
} atomic_flag;

typedef _Atomic _Bool              atomic_bool;
typedef _Atomic char               atomic_char;
typedef _Atomic signed char        atomic_schar;
typedef _Atomic unsigned char      atomic_uchar;
typedef _Atomic short              atomic_short;
typedef _Atomic unsigned short     atomic_ushort;
typedef _Atomic int                atomic_int;
typedef _Atomic unsigned int       atomic_uint;
typedef _Atomic long               atomic_long;
typedef _Atomic unsigned long      atomic_ulong;
typedef _Atomic long long          atomic_llong;
typedef _Atomic unsigned long long atomic_ullong;
/* We don't support char16_t, char32_t, or wchar_t in libcore */
typedef _Atomic int_least8_t       atomic_int_least8_t;
typedef _Atomic uint_least8_t      atomic_uint_least8_t;
typedef _Atomic int_least16_t      atomic_int_least16_t;
typedef _Atomic uint_least16_t     atomic_uint_least16_t;
typedef _Atomic int_least32_t      atomic_int_least32_t;
typedef _Atomic uint_least32_t     atomic_uint_least32_t;
typedef _Atomic int_least64_t      atomic_int_least64_t;
typedef _Atomic uint_least64_t     atomic_uint_least64_t;
typedef _Atomic int_fast8_t        atomic_int_fast8_t;
typedef _Atomic uint_fast8_t       atomic_uint_fast8_t;
typedef _Atomic int_fast16_t       atomic_int_fast16_t;
typedef _Atomic uint_fast16_t      atomic_uint_fast16_t;
typedef _Atomic int_fast32_t       atomic_int_fast32_t;
typedef _Atomic uint_fast32_t      atomic_uint_fast32_t;
typedef _Atomic int_fast64_t       atomic_int_fast64_t;
typedef _Atomic uint_fast64_t      atomic_uint_fast64_t;
typedef _Atomic intptr_t           atomic_intptr_t;
typedef _Atomic uintptr_t          atomic_uintptr_t;
typedef _Atomic size_t             atomic_size_t;
typedef _Atomic ptrdiff_t          atomic_ptrdiff_t;
typedef _Atomic intmax_t           atomic_intmax_t;
typedef _Atomic uintmax_t          atomic_uintmax_t;


/* Initialise atomics simply using assignment */
#define ATOMIC_VAR_INIT(value) value
#define atomic_init(object, value) (*object = ATOMIC_VAR_INIT(value))

/* Kill dependency currently does nothing */
#define kill_dependency(value) value

#define atomic_thread_fence __atomic_thread_fence
#define atomic_signal_fence __atomic_signal_fence

#define atomic_is_lock_free(obj) \
	__atomic_is_lock_free(sizeof(obj), obj)

#define atomic_store_explicit __atomic_store_n
#define atomic_store(object, desired) \
	atomic_store_explicit(object, desired, memory_order_seq_cst)

#define atomic_load_explicit __atomic_load_n
#define atomic_load(object, desired) \
	atomic_load_explicit(object, desired, memory_order_seq_cst)

#define atomic_exchange_explicit __atomic_exchange_n
#define atomic_exchange(object, desired) \
	atomic_exchange_explicit(object, desired, memory_order_seq_cst)

#define atomic_compare_exchange_strong_explicit( \
	object, \
	expected, \
	desired, \
	success_order, \
	failure_order \
) __atomic_compare_exchange_n( \
	object, \
	expected, \
	desired, \
	false, \
	success_order, \
	failure_order \
)
#define atomic_compare_exchange_strong(object, expected, desired) \
	atomic_compare_exchange_strong_explicit(\
		object, \
		expected, \
		desired, \
		memory_order_seq_cst, \
		memory_order_seq_cst \
	)

#define atomic_compare_exchange_weak_explicit( \
	object, \
	expected, \
	desired, \
	success_order, \
	failure_order \
) __atomic_compare_exchange_n( \
	object, \
	expected, \
	desired, \
	true, \
	success_order, \
	failure_order \
)
#define atomic_compare_exchange_weak(object, expected, desired) \
	atomic_compare_exchange_strong_explicit(\
		object, \
		expected, \
		desired, \
		memory_order_seq_cst, \
		memory_order_seq_cst \
	)

#define atomic_fetch_add_explicit __atomic_fetch_add
#define atomic_fetch_add(object, operand) \
	atomic_fetch_add_explicit(object, operand, memory_order_seq_cst)

#define atomic_fetch_sub_explicit __atomic_fetch_sub
#define atomic_fetch_sub(object, operand) \
	atomic_fetch_sub_explicit(object, operand, memory_order_seq_cst)

#define atomic_fetch_or __atomic_fetch_or
#define atomic_fetch_or(object, operand) \
	atomic_fetch_or_explicit(object, operand, memory_order_seq_cst)

#define atomic_fetch_xor __atomic_fetch_xor
#define atomic_fetch_xor(object, operand) \
	atomic_fetch_xor_explicit(object, operand, memory_order_seq_cst)

#define atomic_fetch_and __atomic_fetch_and
#define atomic_fetch_and(object, operand) \
	atomic_fetch_and_explicit(object, operand, memory_order_seq_cst)

#define ATOMIC_FLAG_INIT (atomic_flag){ .byte = 0 }

static inline _Bool atomic_flag_test_and_set_explicit(\
	volatile atomic_flag *object,
	memory_order order,
) {
	return __atomic_test_and_set(object->byte, order);
}
#define atomic_flag_test_and_set(object) \
	atomic_flag_test_and_set_explicit(object, memory_order_seq_cst)

static inline _Bool atomic_flag_clear_explicit(\
	volatile atomic_flag *object,
	memory_order order,
) {
	return __atomic_clear(object->byte, order);
}
#define atomic_flag_clear(object) \
	atomic_flag_clear_explicit(object, memory_order_seq_cst)
