<!--
	Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)

	SPDX-License-Identifier: BSD-2-Clause
-->

seL4 Core Libraries
===================

The seL4 core libraries provide a partitioned subset of the ISO/IEC
9899:2018 C Standard library. This implementation uses GCC builtins
(which are also provided by `clang`) where possible so it should not be
expected to work with other C compilers.

`libcore`
---------

This library contains a subset of the C standard library that uses a
platform independent interface.

Specifically, `libcore` provides the following subset of the C standard
library.

 - `<assert.h>`
 - `<float.h>`
 - `<iso646.h>`
 - `<limits.h>`
 - `<setjmp.h>`
 - `<stdalign.h>`
 - `<stdatomic.h>`
 - `<stdbool.h>`
 - `<stddef.h>`
 - `<stdint.h>`
 - `<stdlib.h>`
   - `div_t`, `ldiv_t`, `lldiv_t`
   - `EXIT_SUCCESS`, `EXIT_FAILURE`
   - numeric conversion (7.22.1)
   - allocation with pluggable heap (7.22.3)
   - searching and sorting (7.22.5)
   - integer arithmetic (7.22.6)
 - `<stdnoreturn.h>`
 - `<string.h>`

Notably, `libcore` does not provide any of the following:

 - interaction with the multithreading or multiprocessing environment
   beyond `exit`, `abort`, and friends,
 - `errno`,
 - support for C-style strings and characters outside of what is
   required in `<string.h>` and `<stdlib.h>`,
 - pseudo-random number generation,
 - mathematics beyond that required for `<stdlib.h>`
 - floating point exception environment,
 - text formatting,
 - text locales,
 - I/O operations,
 - type-generic math,
 - signals,
 - process exit,
 - environment variables,
 - threads,
 - timing operations,
 - unicode utilities, or
 - multibyte string and wide character utilities.

The subset has been chosen to select the most commonly used utilities
from the standard library but to avoid interfaces that do not lend
themselves to the development of optimal systems, that are unsafe or
non-reentrant, and that would require more work to maintain than more
composable and ergonomic alternatives.

`libutils`
----------

Common utilities not provided by the standard library.

`libtext`
---------

This library contains routines for manipulating streams of unicode
characters, UTF-8 strings, and creating unicode character and UTF-8
string literals. This library also provides interfaces for formatting
text streams.

`libio`
-------

This library contains interfaces for interacting with block and stream
data between interfaces, processes, and devices.

`libprocess`
------------

This library contains routines for interacting with the multiprocessing
environment.

`libthread`
-----------

This provides atomic and synchronisation primitives as well as a simple
user-level co-operative threading implementation. It also has a
pluggable backend for spreading threads over multiple OS-level threads
in a m:n fashion.
