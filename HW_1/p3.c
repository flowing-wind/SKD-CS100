/* CS100 Fall 2026 - HW1 Problem 3: Sum and maximum
 *
 * Read integers until a 0; print the sum and the maximum.
 * No arrays or dynamic memory allocation. Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your code here */
    int sum = 0;
    int input = 1;
    int max = 0;
    int flag = 1;

    while (1)
    {
        scanf("%d", &input);

        if (input == 0)
            break;
        sum += input;
        if (flag || input > max)
        {
            max = input;
            flag = 0;
        }
    }

    printf("sum: %d\n", sum);
    printf("maximum: %d\n", max);

    return 0;
}
