#include "main.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int tmp;
	int fts;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (tmp = n, fts = 0; (tmp >>= 1) > 0; fts++)
		;

	for (; fts >= 0; fts--)
	{
		if ((n >> fts) & 1)
			printf("1");
		else
			printf("0");
	}
}
