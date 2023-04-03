#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: prints all possible combinations of single-digit numbers
 * Return: Always 0 (success)
 */
int main(void)
{
int i;
for (i = 48; i <= 57; i++)
{
putchar(i);
if (i < 57)
{
putchar(44);
putchar(32);
}
}
putchar('\n');
return (0);
}
