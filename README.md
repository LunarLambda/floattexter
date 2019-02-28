# FloatTexter

Inspired by [this tweet](https://twitter.com/LunarLambda/status/1096227870345703425).
This program generates C programs which print the given string, stored as an array of floats.

## Configuration

`config.h`:
- digits: Number of digits used for printing float values. Defaults to `9`.

`config.mk`:
- CC: C Compiler. Defaults to `clang`.
- CFLAGS: C Compiler Flags. Defaults to `-O2 -std=c99 -Wall`.
- PREFIX: Prefix used for `make install`. Defaults to `/usr/local`.

## Compilation

Run `make`.

## Usage

`floattexter <string>` will print the generated program to stdout.

## Example

![Example](https://cdn.discordapp.com/attachments/506367803473788930/546036604846735360/Lf02KqNV.png)
