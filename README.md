# Libasm Unit Test

A unit test for the 42 curriculum libasm project.

Requires criterion for testing of the bonus, which can be found
[here](https://github.com/Snaipe/Criterion).

## How to Run

First, place your library (must be named libasm.a for mandatory functions,
or libasm_bonus.a for mandatory and bonus functions) inside the repo directory.
Then:

```bash
./run.sh
```
Test all 6 mandatory functions.

```bash
./run.sh test
```
Test all 6 mandatory functions.

```bash
./run.sh bonus
```
Test all 6 mandatory functions, and all 5 bonus functions.

```bash
./run.sh nocrit
```
Tests all 6 mandatory functions. Does not require criterion.
