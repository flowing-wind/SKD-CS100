# CS100 Fall 2026 - HW2 starter package

Contents: `p3.c` `p4.c` `p5.c` — one file per programming problem, already
correctly named — plus this README. There is intentionally **no Makefile**:
you compile by typing the `gcc` command yourself. (On Gradescope the
autograder builds your files with its own trusted Makefile, so you do not
need to write one.)

Problems 1 and 2 are online objective questions on the Gradescope
assignment **HW2_p1** (C basics, then bash & git). This package is for the
three programming problems.

## Compile (type it yourself)

Open a terminal (WSL) in the directory containing the files. The command
has the same shape for all three problems — only the file name changes.

Minimal form (just builds and runs):

```sh
gcc p3.c -o p3
```

Advanced form (recommended — this is what we test with):

```sh
gcc p3.c -o p3 -std=c17 -Wall -Wpedantic -Wextra -Werror -fsanitize=undefined -fsanitize=address
```

Type it out instead of copy-pasting, and replace both `p3`'s with the
problem you are building: `p4` or `p5`.

What each option does:

| option | what it does |
| --- | --- |
| `-std=c17` | Use the C17 language standard (the course standard). |
| `-Wall` `-Wextra` | Turn on the standard and the extra sets of warnings. |
| `-Wpedantic` | Warn about anything that is not strict ISO C. |
| `-Werror` | Treat every warning as an error, so a warning can never slip through. |
| `-fsanitize=undefined` `-fsanitize=address` | Runtime checkers: UBSan reports undefined behaviour such as signed overflow; ASan reports memory errors (out-of-bounds, use-after-free) with exact line numbers. |

## What the autograder requires

On Gradescope your code is built by the course's trusted Makefile (any
Makefile you submit is replaced) with the same base checks, plus small
per-problem additions: `-O2 -g` for p3, `-Wno-unused-parameter` for p4,
`-O2` for p5. If your program compiles locally with the advanced command,
it compiles on Gradescope. A compilation error or a failed static check
earns 0 points for that problem.

## Run

```sh
./p3              # type the input by hand, or feed it from a file:
./p3 < input.txt
```

Problem 4 reads no standard input — pass the GCC arguments on the command
line instead:

```sh
./p4 -std=c17 -Wall hello.c -o hello
```

## Tips

- Press the **up arrow key** in the terminal to bring back the last
  command you typed; press it repeatedly to walk further back through
  your history. You will never need to retype a long `gcc` line.
- If linking fails with an error about `-lasan` / `-lubsan`, install the
  sanitizer runtimes once: `sudo apt install libasan8 libubsan1`.

## Submit

Gradescope assignment **HW2_programming**: upload any subset of
`p3.c`-`p5.c` (as many times as you like), or submit a GitHub repository
with the three files at the top level. Each problem is graded
independently and is worth 100 points (300 total). Keep the file names
exactly as given.

Problems 1 and 2 live on the separate online assignment **HW2_p1**.

Deadline: **Wed, Oct 22, 2026, 23:59**. See the full handout on the course
home page.
