/* CS100 Fall 2026 - HW1 Problem 2: Find Bugs!
 *
 * BinB's buggy program is in the handout. Put your FIXED program here.
 * Do not rename this file: the autograder builds p2.c.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your fixed code here */
    int num;
    int sum = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        int score;
        scanf("%d", &score);
        sum += score;
    }

    double average = (double)sum / num;

    printf("How many students are there?\n");
    printf("What are their scores?\n");

    if (average == 60)
        printf("Good!\n");
    else if (average > 60)
        printf("Excellent!\n");
    else
        printf("Bad!\n");

    printf("Average score is %.2f.\n", average);

    return 0;
}
