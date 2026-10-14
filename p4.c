/* CS100 Fall 2026 - HW2 Problem 4: GCC argument descriptor
 *
 * Read GCC-style command-line arguments (argv) and print a description
 * for each of them, in order. No standard input in this problem.
 * Do not rename this file.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /* TODO: your code here */
    (void)argc;
    (void)argv;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-Wall") == 0)
        {
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        }

        else if (strcmp(argv[i], "-Wpedantic") == 0)
        {
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        }

        else if (strcmp(argv[i], "-Wextra") == 0)
        {
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        }

        else if (strcmp(argv[i], "-Werror") == 0)
        {
            printf("-Werror: Make all warnings into errors.\n");
        }

        else if (strcmp(argv[i], "-o") == 0)
        {
            printf("-o %s: Place the primary output in file %s.\n", argv[i + 1], argv[i + 1]);
            i++;
        }

        else if (strcmp(argv[i], "-I") == 0)
        {
            printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", argv[i + 1], argv[i + 1]);
            i++;
        }

        else if (strncmp(argv[i], "-std=", 5) == 0)
        {
            const char *standard = argv[i] + 5;
            const char *num;

            if (strncmp(standard, "c++", 3) == 0)
            {
                num = standard + 3;
                standard = "ISO C++";
            }

            else if (strncmp(standard, "c", 1) == 0)
            {
                num = standard + 1;
                standard = "ISO C";
            }

            if (strncmp(standard, "gnu++", 5) == 0)
            {
                num = standard + 5;
                standard = "GNU dialect of C++";
            }

            else if (strncmp(standard, "gnu", 3) == 0)
            {
                num = standard + 3;
                standard = "GNU dialect of C";
            }

            printf("%s: Set the language standard to %s%s.\n", argv[i], standard, num);
        }

        else
        {
            const char *suffix = strrchr(argv[i], '.');
            const char *yyy;
            if (strcmp(suffix, ".c") == 0)
            {
                yyy = "C source code";
            }

            else if (strcmp(suffix, ".h") == 0)
            {
                yyy = "C/C++ header file";
            }

            else if (strcmp(suffix, ".cpp") == 0 || strcmp(suffix, ".C") == 0 || strcmp(suffix, ".cc") == 0 || strcmp(suffix, ".cxx") == 0)
            {
                yyy = "C++ source code";
            }

            else if (strcmp(suffix, ".hpp") == 0 || strcmp(suffix, ".hxx") == 0)
            {
                yyy = "C++ header file";
            }

            printf("%s: %s as input file.\n", argv[i], yyy);
        }
    }

    return 0;
}
