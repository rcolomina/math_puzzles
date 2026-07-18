# Math Puzzles Solved by Coding

A personal collection of recreational mathematics, algorithm, and cryptography
puzzles, solved in C++, Python, and Rust. Each top-level directory is an
independent topic; a full catalogue with problem statements and solution
approaches lives in [`docs/puzzles_index.pdf`](docs/puzzles_index.pdf)
(build it with `make docs`).

## Layout

| Directory | Topic | Language |
|-----------|-------|----------|
| `arrays_handling/` | Linear-scan array puzzles | C++ |
| `counting_elements/` | Counting / bounding puzzles | C++ |
| `stack_queues/` | Stack & queue puzzles | C++ |
| `graph_algorithms/` | Tree / stack-machine puzzles | C++ |
| `codility_test/` | Assorted Codility tasks | C++ |
| `parallel_compu_primes/` | OpenMP prime sieve | C++ |
| `combinatory/` | Combinatorics | Python |
| `crypto/` | Cryptography (cryptarithms, ciphers, ElGamal) | Python / Rust |
| `integrate/` | A LaTeX math write-up | LaTeX |
| `random_numbers/` | `alea.h` threaded PRNG helper | C++ header |

Shared tooling lives in `common/`:

- `common/log.h` — header-only leveled logging for C++.
- `common/log.py` — matching logging helper for Python.
- `common/topic.mk` — shared Make rules that every topic `Makefile` includes.

## Building and running

A root `Makefile` auto-discovers every topic directory that includes
`common/topic.mk`:

```sh
make            # compile every C++ topic
make run        # build, then run every solution
make clean      # remove built binaries
make docs       # (re)build docs/puzzles_index.pdf
make help       # list targets and discovered topics
```

Every `*.cpp` in a topic builds to a binary of the same base name, so dropping
in a new source file needs no Makefile edit. Compiled binaries are **not**
committed — they are rebuilt from source.

- Python puzzles run directly, e.g. `python3 combinatory/cutting_strings.py`.
- The Rust ElGamal demo builds with `cargo run` inside `crypto/elgamal-rust/`.

## Logging

Diagnostic output is routed through the shared loggers and gated by the
`VERBOSE` environment variable (`0`=error, `1`=warn, `2`=info [default],
`3`=debug). Final answers log at *info*; step traces at *debug*:

```sh
./arrays_handling/odd_occur_array            # info only
VERBOSE=3 ./arrays_handling/odd_occur_array  # full debug trace
VERBOSE=3 python3 crypto/special_sum/special_sum.py
```

## Adding a new puzzle

Use the scaffold script to create a puzzle already wired into the build and
logging conventions:

```sh
scripts/new_puzzle.sh <topic> <name> [cpp|py]
# e.g.
scripts/new_puzzle.sh dynamic_programming knapsack cpp
scripts/new_puzzle.sh combinatory permutations py
```

For a C++ puzzle in a new topic it also drops a one-line `Makefile` (and a
`.gitignore`) so the root build discovers the whole topic automatically. Then
add a subsection for it to `docs/puzzles_index.tex`.

## Cryptography — *Understanding Cryptography*

Solutions to exercises from *Understanding Cryptography* live under
`crypto/undertanding_cryptography/`. The book is available at:
http://khosach.info/store/msresource/it/book/Understanding-Cryptography.pdf

Chapter 1, Exercise 1 (`chapter01/problem01.py`) recovers a substitution
cipher via English letter-frequency analysis, in Python 3.
