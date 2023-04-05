#include "main.h"

int scnd_sqrt_func(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: the resulting square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (scnd_sqrt_func(n, 0));
}

/**
 * scnd_sqrt_func - recurses to find the natural
 * square root of a number
 * @n: number to calculate the sqaure root
 * @i: iteration
 *
 * Return: the resulting square root
 */
int scnd_sqrt_func(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (scnd_sqrt_func(n, i + 1));
}
