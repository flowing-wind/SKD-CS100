/* CS100 Fall 2026 - HW3 Problem 2: Palindrome
 *
 * Read n strings and test whether each of them is a palindrome.
 * Print "Yes" / "No" on one line per string.
 * Use dynamic memory to store each input string (no fixed-size arrays).
 * Do not rename this file.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* TODO: your code here */
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int len;
        scanf("%d", &len);
        char *str = (char *)malloc(len + 1);
        scanf("%s", str);

        int left = 0;
        int right = len - 1;
        int res = 1;

        while (left < right)
        {
            if (str[left] != str[right])
            {
                res = 0;
                break;
            }
            left++;
            right--;
        }

        printf("%s\n", res ? "Yes" : "No");

        free(str);
    }

    return 0;
}
