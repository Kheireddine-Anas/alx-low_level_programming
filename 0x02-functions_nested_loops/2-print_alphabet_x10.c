#include <stdio.h>
/**
* print_alphabet - Prints the alphabet in lowercase
*
* Return : Always 0 (success)
*/
void print_alphabet(void)
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
return (0);
}
