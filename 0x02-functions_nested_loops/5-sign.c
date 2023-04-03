#include "main.h"
/**
* print_sign -  Check if number negative or positive or 0.
*
* @n: The integer input number
*
* Return: 1 if > 0 and 1 if < 0, otherwise 0.
*/
int print_sign(int n)
{
if (n > 0)
{
_putchar(43);
return (1);
}
else if (n < 0)
{
_putchar(45);
return (-1);
}
else
{
_putchar(48);
return (0);
}
_putchar('\n');
}
