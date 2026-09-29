# CS100 Fall 2026 - HW1 starter package

Contents: `p2.c` `p3.c` `p4.c` `p5.c` — one file per problem, already
correctly named — plus this README. There is intentionally **no Makefile**:
for HW1 you compile by typing the `gcc` command yourself. (On Gradescope
the autograder builds your files with its own trusted Makefile, so you do
not need to write one.)

## Compile (type it yourself)

Open a terminal (WSL) in the directory containing the files. The command
has the same shape for all four problems — only the file name changes.

Minimal form (just builds and runs):

```sh
gcc p3.c -o p3
```

Advanced form (recommended — this is what we test with):

```sh
gcc p3.c -o p3 -std=c17 -Wall -Wpedantic -Wextra -Werror -fsanitize=undefined -fsanitize=address -Wvla -Wno-error=vla
```

Type it out instead of copy-pasting, and replace both `p3`'s with the
problem you are building: `p2`, `p4` or `p5`.

What each option does:

| option | what it does |
| --- | --- |
| `-std=c17` | Use the C17 language standard (the course standard). |
| `-Wall` `-Wextra` | Turn on the standard and the extra sets of warnings. |
| `-Wpedantic` | Warn about anything that is not strict ISO C. |
| `-Wvla` `-Wno-error=vla` | Warn when a variable-length array (VLA) is used — and keep it a *warning* even though `-Werror` is on, so your local build still succeeds. On the autograder a VLA is an error instead. |
| `-Werror` | Treat every warning as an error, so a warning can never slip through. |
| `-fsanitize=undefined` `-fsanitize=address` | Runtime checkers: UBSan reports undefined behaviour such as signed overflow; ASan reports memory errors (out-of-bounds, use-after-free) with exact line numbers. |

**Variable-length arrays are not allowed.** An array whose length is a
variable, like `int a[n];`, is a VLA. The advanced command only *warns*
about it (via `-Wvla`), but on the autograder it is a compilation
**error** and the problem scores 0 — always declare arrays with a fixed
size.

## What the autograder requires

On Gradescope your code is built by the course's trusted Makefile with the same
checks, except that a VLA is a compilation **error** there (`-Werror=vla`)
rather than a warning — one single set of flags for all four problems. If
your program compiles locally with the advanced command and is VLA-free,
it compiles on Gradescope.

## Run

```sh
./p3              # type the input by hand, or feed it from a file:
./p3 < input.txt
```

## Tips

- Press the **up arrow key** in the terminal to bring back the last
  command you typed; press it repeatedly to walk further back through
  your history. You will never need to retype a long `gcc` line.
- If linking fails with an error about `-lasan` / `-lubsan`, install the
  sanitizer runtimes once: `sudo apt install libasan8 libubsan1`.

## Submit

Gradescope assignment **HW1_programming**: upload any subset of
`p2.c`-`p5.c` (as many times as you like), or submit a Git repository with
the four files at the top level. Each problem is graded independently and
is worth 100 points (400 total). Keep the file names exactly as given.

Problem 1 is a separate online assignment (**HW1_p1**) on Gradescope.

Deadline: **Tue, Oct 13, 2026, 23:59**. See the full handout on the course
home page.
