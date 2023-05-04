#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: char string
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int all, pwr;
	int sln;

	if (b == NULL)
		return (0);

	for (sln = 0; b[sln]; sln++)
	{
		if (b[sln] != '0' && b[sln] != '1')
			return (0);
	}

	for (pwr = 1, all = 0, sln--; sln >= 0; sln--, pwr *= 2)
	{
		if (b[sln] == '1')
			all += pwr;
	}

	return (all);
}
