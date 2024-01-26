<h1 align="center">
	<p>
	get_next_line
	</p>
	<img src="https://github.com/ayogun/42-project-badges/blob/main/badges/get_next_linem.png">
</h1>

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br><br>
  This project is about programming a function that returns<br>
  a line read from a file descriptor<br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/aaron-22766/42_get_next_line?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/aaron-22766/42_get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/aaron-22766/42_get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/aaron-22766/42_get_next_line?color=green" />
</p>

---

## 🗣 About

May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line. It is time to start working on this function, which will be essential for your future projects. This project will not only allow you to add a very convenient function to your collection,
but it will also make you learn a highly interesting new concept in C programming: static variables.
variables.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 🗒 Notice

Bonus for handling mulitple file descriptors at the same time was implemented using a linked list to replicate a map in order to save memory by not having to preallocate FD_MAX amount of integers.
