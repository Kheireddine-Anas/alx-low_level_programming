#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: print 0-9 with \n
 * Return: Always 0 (success)
 */
int main(void)
{
int i;
for (i = 48; i <= 57; i++)
{
putchar(i);
}
putchar('\n');
return (0);
}
