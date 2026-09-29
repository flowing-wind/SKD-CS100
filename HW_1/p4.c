/* CS100 Fall 2026 - HW1 Problem 4: Second maximum and second minimum
 *
 * No arrays or dynamic memory allocation (the last 5 test cases require
 * O(1) extra space). Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your code here */
    int num, x;
    scanf("%d", &num);

    int max;
    int max_2;
    int min;
    int min_2;
    int flag = 0;

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &x);

        if (i == 0)
        {
            max = x;
            min = x;
        }
        else
        {
            if (flag == 0 && x != max)
            {
                if (x > max)
                {
                    max_2 = max;
                    max = x;
                    min_2 = x;
                    min = max_2;
                }
                else
                {
                    max_2 = x;
                    min_2 = max;
                    min = x;
                }
                flag = 1;
            }
            else if (flag)
            {
                if (x > max)
                {
                    max_2 = max;
                    max = x;
                }
                else if (x > max_2 && x < max)
                {
                    max_2 = x;
                }

                if (x < min)
                {
                    min_2 = min;
                    min = x;
                }
                else if (x < min_2 && x > min)
                {
                    min_2 = x;
                }
            }
        }
    }

    printf("%d %d\n", max_2, min_2);

    return 0;
}
