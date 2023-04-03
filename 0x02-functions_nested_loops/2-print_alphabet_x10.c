#include <stdio.h>
/**
* print_alphabet_x10 - Prints the alphabet in lowercase x10
*
* Return : Always 0 (success)
*/
void print_alphabet_x10(void)
{
int firstloop, i;
for (firstloop = 1; firstloop <= 10; firstloop++)
{
for (i = 'a'; i <= 'z'; i++)
{
putchar(i);
}
putchar('\n');
}
}
