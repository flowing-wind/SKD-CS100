# CS100 Fall 2026 - HW3 starter package

Contents: `p2.c` `p3.c` `p4.c` — one file per programming problem, already
correctly named — plus this README. There is intentionally **no Makefile**:
you compile by typing the `gcc` command yourself. (On Gradescope the
autograder builds your files with its own trusted commands, so you do not
need to write one.)

Problem 1 is a set of online objective questions on the Gradescope
assignment **HW3_p1**. This package is for the three programming problems
(P2–P4) on **HW3_programming**.

## Compile (type it yourself)

Open a terminal (WSL) in the directory containing the files. The command
has the same shape for all three problems — only the file name changes.

Minimal form (just builds):

```sh
gcc p2.c -o p2
```

Recommended form (this is close to what we test with):

```sh
gcc p2.c -o p2 -std=c17 -Wall -Wpedantic -Wextra -Werror -fsanitize=undefined -fsanitize=address
```

Type it out instead of copy-pasting, and replace both `p2`'s with the
problem you are building: `p3` or `p4`.

## A note on P3 and P4 (no `main`!)

- **P3 (String manipulation)**: your `p3.c` contains **only the six
  `hw3_*` functions — do NOT write a `main`**. You cannot run `p3.c` on its
  own. To test it locally, write a separate small `test.c` with a `main`
  that calls your functions, and compile them together:
  `gcc p3.c test.c -o test -std=c17 ...` then `./test`.
- **P4 (Memory Leak Checker)**: your `p4.c` is a header-style file (with
  include guards) that the course driver `#include`s. It has no `main`
  either. Test it the same way: a `test.c` that does `#define`-free
  `malloc/calloc/free` calls guarded by your macros.

## Run

```sh
./p2              # P2 reads input; feed it from a file:
./p2 < input.txt
```

P3 and P4 are exercised by the course driver, not run directly.

## What the autograder requires

On Gradescope your code is built by the course's trusted commands (any
Makefile you submit is replaced). P2 is compiled as a standalone program;
P3 is compiled together with the course's test driver; P4 is `#include`d by
the course's driver. A compilation error earns 0 points for that problem.

## Submit

Gradescope assignment **HW3_programming**, submission via a **GitHub
repository only** (no file upload): create a private repository with
`p2.c`, `p3.c`, `p4.c` at the top level, then on Gradescope choose the
GitHub submission method, select your repository and branch. Each problem
is graded independently and is worth 100 points (300 total). Keep the file
names exactly as given.

Deadline: **Mon, Nov 3, 2026, 23:59**. See the full handout on the course
home page.
