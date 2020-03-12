# Libasm Unit Test

A unit test for the 42 curriculum libasm project.

Requires criterion for testing of the bonus, which can be found
[here](https://github.com/Snaipe/Criterion).

## How to Run

First, place your library (must be named libasm.a) inside the repo directory.
Then:

```bash
./run.sh
```
Test all functions that are present in your libasm.a. If any functions are
absent, they will be skipped.

```bash
./run.sh test
```
Equivalent to './run.sh'

```bash
./run.sh nocrit
```
Does not require criterion. Will only test for the 6 mandatory functions, which
MUST be present for this test to run.
