#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: print alpha from a-z and A-Z with \n
 * Return: Always 0 (success)
 */
int main(void)
{
int i;
for (i = 97; i <= 122; i++)
{
	putchar(i);
}
for (i = 65; i <= 90; i++)
{
	putchar(i);
}
putchar('\n');
return (0);
}
