#include "main.h"
#include <stdio.h>
/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @n: a pointer to the number to clear the bit in
 * @index: the index of the bit to clear
 * Return: 1 Successful, or -1 Error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int dst = 1ul << index;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((*n & dst) != 0)
		*n ^= dst;

	return (1);
}
