#include "main.h"
/**
* print_last_digit -  show last digit of number.
*
* @n: input integer number
*
* Return: the last digit of the number
*/
int print_last_digit(int n)
{
int last;
last = n % 10;
if (last < 0)
{
_putchar(-last + 48);
return (-last);
}
else
{
_putchar(last + 48);
return (last);
}
}
