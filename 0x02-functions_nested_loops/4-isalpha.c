#include "main.h"
/**
* _isalpha -  shows 1 if the input is a letter otherwise 0.
*
* @c: The character in ASCII
*
* Return: 1 if a letter, otherwise 0.
*/
int _isalpha(int c)
{
if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
{
return (1);
}
else
{
return (0);
}
_putchar('\n');
}
