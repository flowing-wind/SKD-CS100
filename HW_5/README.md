# CS100 Fall 2026 - HW5 starter package

Contents: `p2.cc` `p3.cc` `p4.cc` — one file per programming problem, already
correctly named — plus this README, and three optional helper files
(`example1.cc`, `example2.cc`, `compile_test.cc`) for Problem 2 taken from
the class examples. There is intentionally **no Makefile**: you compile by
typing the `g++` command yourself. (On Gradescope the autograder builds your
files with its own trusted commands, so you do not need to write one.)

Problem 1 is a set of online objective questions on the Gradescope assignment
**HW5_p1**. This package is for the three programming problems (P2–P4) on
**HW5_programming**.

This is the first C++ homework: submit `.cc` files, compile with `g++` and
`-std=c++17`.

## Compile (type it yourself)

Open a terminal (WSL) in the directory containing the files. The command has
the same shape for all three problems — only the file name changes.

`p2.cc` and `p3.cc` are header-style files: they define the class `Dynarray`
and have no `main`. To test them locally, compile together with your own test
program, e.g.:

```sh
g++ example1.cc -o example1 -std=c++17 -Wall -Wpedantic -Wextra -Werror -fsanitize=undefined -fsanitize=address
./example1
```

The provided `example1.cc`/`example2.cc` and `compile_test.cc` already
`#include "p2.cc"` for you, so you compile them directly.

`compile_test.cc` checks the interface requirements of Problem 2
(constructors, copy/move control, `noexcept`, ...) at compile time:

```sh
g++ compile_test.cc -o compile_test -std=c++17 -Wall -Wpedantic -Wextra -Werror -fsanitize=undefined -fsanitize=address
```

`p4.cc` is a header-style file like `p2.cc`/`p3.cc`: define the two class
templates `UniquePtr<T>` and `SharedPtr<T>` (no `main`). Test it together
with your own small test program that starts with `#include "p4.cc"`, e.g.
`g++ mytest.cc -o mytest -std=c++17 ...`. Do **not** include `<memory>` in
`p4.cc`.

Recommended flags (this is close to what we test with):

```sh
-std=c++17 -Wall -Wpedantic -Wextra -Werror -Wzero-as-null-pointer-constant -fsanitize=undefined -fsanitize=address
```

Type it out instead of copy-pasting, and use the ↑ key to recall and edit the
previous command.

## Submission

Submit to Gradescope **HW5_programming** from your GitHub repository (upload
is disabled). The repository must contain `p2.cc`, `p3.cc` and `p4.cc` at its
top level, exactly with these names. Extra helper files (e.g. your own test
programs) do not interfere with grading.

## Notes

- Do **not** use `std::vector`/`std::deque`/`std::list` in P2/P3: the graders
  check for forbidden includes and constructs.
- P2/P3 files are copied into the official driver and compiled as part of it;
  keep them self-contained (no includes of files that are not standard
  headers).
- Deadlines and grading policy are on the course page and the handout.
