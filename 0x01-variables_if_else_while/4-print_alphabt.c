#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: print alpha from a-z without e & q with \n
 * Return: Always 0 (success)
 */
int main(void)
{
int i;
for (i = 97; i <= 122; i++)
{
if (i != 'e' && i != 'q')
{
	putchar(i);
}
}
putchar('\n');
return (0);
}
