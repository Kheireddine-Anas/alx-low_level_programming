#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Main - entry point
 * Description: checking n if it positive or negative or equal zero
 * Return: 0
 * main function for alx
 */
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
if (n > 0)
{
printf("%d is positive\n", n);
}
else if (n == 0)
{
printf("%d is zero\n", n);
}
else if (n < 0)
{
printf("%d is negative\n", n);
}
return (0);
}
