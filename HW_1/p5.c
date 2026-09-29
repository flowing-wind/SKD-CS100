/* CS100 Fall 2026 - HW1 Problem 5: Platinum Lion Dog's Bus Journey
 *
 * Input length is unknown: check the return value of scanf.
 * No arrays or dynamic memory allocation. Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your code here */
    int n;
    scanf("%d", &n);

    int out, in;
    int Impossible = 0;
    int cnt = 0;

    while (scanf("%d %d", &out, &in) == 2)
    {
        n -= out;
        if (n < 0)
        {
            Impossible = 1;
            break;
        }
        n += in;

        cnt += 1;
    }

    char query;
    scanf("%c", &query);

    if (Impossible)
        printf("Impossible.\n");
    else if (query == 'p')
        printf("%d\n", n);
    else if (query == 's')
        printf("%d\n", cnt);

    return 0;
}
