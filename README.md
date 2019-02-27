# FloatTexter: The dumbest way of encoding text at compile time

Inspired by [this tweet](https://twitter.com/LunarLambda/status/1096227870345703425).
This program generates C programs which print a float array as a text string.

## Configuration

`config.h`:
- digits: Number of digits used for printing float values. Defaults to 7.

`config.mk`:
- CC: C Compiler. Defaults to `clang`.
- CFLAGS: C Compiler Flags. Defaults to `-O2`.
- PREFIX: Prefix used for `make install`. Defaults to `/usr`.

## Compilation and Installation

Just hit `make install`. ¯\\\_(ツ)\_/¯

## Usage

`floattexter <string>` will print the generated program to stdout, so just redirect or pipe it to where you need it.

## Example

![Example](https://cdn.discordapp.com/attachments/506367803473788930/546036604846735360/Lf02KqNV.png)

## FAQ

Q: Why?

A: Why not.
