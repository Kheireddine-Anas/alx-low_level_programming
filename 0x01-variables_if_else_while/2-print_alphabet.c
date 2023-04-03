#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 * Description: printf alphabet a-z with \n
 * Return: Always 0 (success)
 */
int main(void)
{
int i;
for (i = 97; i <= 122; i++)
{
	putchar(i);
}
putchar('\n');
return (0);
}
