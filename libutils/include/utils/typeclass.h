/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

/*
 * Tools for defining and instantiating type classes.
 *
 * Each type class defines a collection of operations that can be
 * performed on an instance of that type class.
 */

#include <utils.h>

/* Prefix a name into the `Utils_TypeClass` namespace */
#define Utils_TCPrefix(label) Utils_NSJoin(Utils_TC, label)

/* The name of a typeclass instance */
#define Utils_TCInstance(typeclass) Utils_TCPrefix(label)

/* Declaration of a typeclass instance */
#define Utils_TCDef(typeclass) \
	typedef struct { \
		void *instance; \
		struct Utils_TCInstance(typeclass) *vtable; \
	} Utils_TCInstance(typeclass)

/* The name of a typeclass method */
#define Utils_TCMethod(typeclass, label) \
	Utils_TCPrefix(Utils_NSJoin(typeclass, method))

#define Utils_TCMethodDef(typeclass, method, ...) \
	typedef Utils_TCMethod(typeclass, method)()

/* Foo typeclass */

typedef struct {
	void *instance;
	struct foo_vtable *vtable;
} foo_t;

typedef ret_t foo_method_a_f(foo_t instance, arg_t a, arg_t b);
typedef ret_t foo_method_b_f(foo_t instance, arg_t a, arg_t b, arg_t c);

typedef struct foo_vtable {
	foo_method_a *method_a;
	foo_method_b *method_b;
} foo_vtable_t;

static inline ret_t foo_method_a(foo_t foo, arg_t a, arg_t b)
{
	if (foo.vtable->method_a == NULL) {
		return RET_DEFAULT;
	} else {
		return foo.vtable->method_a(foo, a, b);
	}
}

static inline ret_t foo_method_b(foo_t foo, arg_t a, arg_t b, arg_t c)
{
	if (foo.vtable->method_a == NULL) {
		return RET_DEFAULT;
	} else {
		return foo.vtable->method_b(foo, a, b, c);
	}
}

/* Bar instance */

typedef struct {
	/* ... */
} bar_t

/* Private instance of foo for bar */
extern foo_vtable_t bar_foo_vtable;
static inline foo_t bar_foo(bar_t *bar)
{
	return (foo_t) {
		.instance = bar,
		.vtable = bar_foo_vtable,
	};
}

/* bar.c */

static ret_t bar_foo_method_a(foo_t foo, arg_t a, arg_t b)
{
	bar_t *bar = foo.instance;

	/* ... */

	return /* ... */;
}

foo_vtable_t bar_foo_vtable = {
	.method_a = bar_foo_method_a,
};
