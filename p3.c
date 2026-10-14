/* CS100 Fall 2026 - HW2 Problem 3: Polynomial evaluation
 *
 * Evaluate P(x) at m given points; print each value rounded to 3 decimals.
 * An array is enough for the coefficients; do not use heap memory and do
 * not use <math.h> (your program is not linked against the math library).
 * Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your code here */
    int n, m, cnt = 0;
    double a[31] = {0};
    scanf("%d", &n);

    // read a_i
    while (cnt <= n && scanf("%lf", &a[cnt]) == 1)
    {
        cnt++;
    }

    // evaluate the polynomial
    scanf("%d", &m);
    double x, ans;
    for (int j = 0; j < m; j++)
    {
        scanf("%lf", &x);
        ans = a[n];
        for (int i = n; i > 0; i--)
        {
            ans = ans * x + a[i - 1];
        }
        printf("%.3f\n", ans);
    }

    return 0;
}
