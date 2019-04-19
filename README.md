# FloatTexter

Inspired by [this tweet](https://twitter.com/lunasorcery/status/1084623111100817408).  
This program generates C programs which print the given string, stored as an array of floats.

## Configuration

In `config.mk`:

Variable | Description             | Default Value
---------|-------------------------|--------------
CC       | C Compiler              | `clang`
CFLAGS   | C Compiler Flags        | `-O2 -std=c11 -Wall -Wextra -Wpedantic`
PREFIX   | Installation Prefix     | `/usr/local`
BINDIR   | Directory for binaries  | `$(PREFIX)/bin`

In `main.c`:

Variable | Description                       | Default Value
---------|-----------------------------------|--------------
PROG_BEG | Program Start                     | `"#include <stdio.h>\n\nstatic float text[] =\n{\n"`
PROG_END | Program End                       | `"};\n\nint main(void)\n{\n    puts((char*)(void*)text);\n}\n"`
TEXT_BEG | Text before number                | `"    "`
TEXT_END | Text after  number                | `",\n"`
DIGITS   | Digits used when printing numbers | `FLT_DECIMAL_DIG` (Requires C11)

## Compilation

Run `make`.

## Installation

Run `make install`.

## Usage

`floattexter <string>` will print the generated program to stdout.

## Examples

```
$ floattexter "Hello, World"
#include <stdio.h>

static float text[] =
{
    1.143139122e+27,
    1.761127013e+14,
    1.744670964e+22,
    0.000000000e+00,
};

int main(void)
{
    puts((char*)(void*)text);
}
```

```
$ floattexter "Hello, World" | clang -o test -x c -
$ ./test
Hello, World
```
