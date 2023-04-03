#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: print z-a with \n
 * Return: Always 0 (success)
 */
int main(void)
{
int i;
for (i = 'z'; i >= 'a'; i--)
{
putchar(i);
}
putchar('\n');
return (0);
}
