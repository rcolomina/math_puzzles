# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

A personal collection of recreational math, algorithm, and cryptography puzzles. Each top-level directory is an independent topic. Solutions are written in C++, Python, and Rust depending on the puzzle. Many originate from Codility lessons and the book *Understanding Cryptography* (linked in `README.md`). Light shared tooling lives in `common/` (logging + shared Make rules); topics are otherwise self-contained.

## Layout

Directories group puzzles by topic, not by language:
- `arrays_handling/`, `counting_elements/`, `stack_queues/`, `graph_algorithms/`, `codility_test/` — C++ Codility-style problems, each with a one-line `Makefile` that `include`s `../common/topic.mk`.
- `parallel_compu_primes/` — C++ prime sieve using OpenMP (its Makefile sets `EXTRA_CXXFLAGS := -fopenmp`).
- `combinatory/` — Python (`itertools`-based).
- `random_numbers/` — `alea.h`, a header-only C++ helper.
- `crypto/special_sum/` — Python brute-force cryptarithm solver.
- `crypto/undertanding_cryptography/chapterNN/` — Python solutions to book exercises.
- `crypto/elgamal-rust/` — a Cargo project using the `rust-elgamal` and `rand` crates.
- `integrate/` — a LaTeX writeup (`.tex` + compiled `.pdf`), not code.
- `common/` — shared tooling: `log.h`, `log.py`, `topic.mk`.
- `docs/` — LaTeX index of all puzzles (`puzzles_index.tex` → `.pdf`).
- `scripts/` — `new_puzzle.sh` scaffold generator.

## Building and running

The root `Makefile` auto-discovers every topic directory that has a `Makefile` (those including `common/topic.mk`):
- `make` / `make build` — compile every C++ topic.
- `make run` — build then run every solution.
- `make clean` — remove built binaries.
- `make docs` — build `docs/puzzles_index.pdf` (runs `pdflatex` 3× for TOC/refs).
- `make help` — list targets and discovered topics.

Per topic, `common/topic.mk` auto-discovers every `*.cpp` and builds it to a binary of the **same base name** (e.g. `min_split_diff.cpp` → `min_split_diff`). Adding a `.cpp` needs no Makefile edit. To scaffold a whole new puzzle wired into build + logging, run `scripts/new_puzzle.sh <topic> <name> [cpp|py]`.

- Python puzzles run directly, e.g. `python3 combinatory/cutting_strings.py` (all are Python 3).
- `crypto/elgamal-rust/`: `cargo build` / `cargo run` from within that directory.
- Known incomplete: `graph_algorithms/word_machine.cpp` is WIP (excluded from the build via `EXCLUDE`), and `codility_test/weeks_in_hawaii.cpp` is an empty stub.

## Logging

Both `common/log.h` (C++ macros `LOG_ERROR/WARN/INFO/DEBUG`) and `common/log.py` (`get_logger`) gate output on the `VERBOSE` env var: `0`=error, `1`=warn, `2`=info (default), `3`=debug. Final answers are logged at info; step traces at debug. Prefer these over raw `cout`/`print` when adding or editing solutions. C++ files include the header as `#include "../common/log.h"`; Python files walk up to the repo root to `from common.log import get_logger`.

## Conventions

- Compiled C++ binaries are **not** committed — they are git-ignored per topic (`*/.gitignore`) and rebuilt from source with `make`.
- The root `.gitignore` also excludes editor backups (`*~`), LaTeX aux files, `__pycache__`, and the Rust `target/`.
- There is no test framework; the `test/` directory is an empty placeholder. Puzzles typically self-verify via hardcoded test cases in `main` whose results are logged at info level.
