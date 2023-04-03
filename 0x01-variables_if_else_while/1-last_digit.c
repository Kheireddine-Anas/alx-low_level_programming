#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 * Description: checks on the last digit of the assigned var
 * Return: Always 0 (success)
 */
int main(void)
{
int n, lastnum;

srand(time(0));
n = rand() - RAND_MAX / 2;
lastnum = n % 10;
printf("Last digit of %d is %d and is", n, lastnum);
if (lastnum > 5)
{
	printf(" greater than 5\n");
}
else if (lastnum < 6 && lastnum != 0)
{
	printf(" less than 6 and not 0\n");
}
else
{
	printf(" 0\n");
}
return (0);
}
