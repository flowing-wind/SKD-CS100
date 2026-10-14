/* CS100 Fall 2026 - HW2 Problem 4: GCC argument descriptor
 *
 * Read GCC-style command-line arguments (argv) and print a description
 * for each of them, in order. No standard input in this problem.
 * Do not rename this file.
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* TODO: your code here */
    (void)argc;
    (void)argv;
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = [%s]\n", i, argv[i]);
    }

    return 0;
}
