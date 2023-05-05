#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index to 1
 * @n: a pointer to the number to set the bit in
 * @index: the index of the bit to set
 * Return: 1 Successful, or -1 Error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1ul << index;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((*n & mask) == 0)
		*n += mask;

	return (1);
}
