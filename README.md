<!--
	Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)

	SPDX-License-Identifier: BSD-2-Clause
-->

seL4 Core Libraries
===================

The seL4 core libraries provide a partitioned subset of the ISO/IEC
9899:2018 C Standard library. This can be used in combination with a
system presenting an operating system personality to construct a
complete C standard library for systems using seL4.

`libcore`
---------

`libcore` contains a subset of the C standard library that uses a
platform independent interface.

`libtext`
---------

`libtext` contains the subset of the C standard library for dealing with
text in C including locale definitions, wide character text, and
multibyte character strings.

`libformat`
-----------

`libformat` contains a generic interface for formatting text streams. 

`libio`
-------

`libio` contains interfaces for interacting with files and streams in
external processes.

`libthread`
-----------

`libthread` provides co-operative multitasking at user level which can
be extended by the environment to m:n threading.

`libmath`
---------

`libmath` contains the routines from the C standard library pertaining
specifically to mathematics.

`libtime`
---------

`libtime` contains routines for working with execution and wall-clock
time.

`libc`
------

`libc` condenses all of the above libraries into a single libc.
