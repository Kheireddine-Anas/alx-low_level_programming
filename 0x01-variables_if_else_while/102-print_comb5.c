#include <stdio.h>
#include <unistd.h>
/**
 * main - Entry point
 * Description: prints all possible combination of 2-digit numbers
 * Return: Always 0 (success)
 */
int main(void)
{
	int n, i, t, r;

	for (n = 48; n <= 57; n++)
	{
		for (i = 48; i <= 57; i++)
		{
			for (t = 48; t <= 57; t++)
			{
				for (r = 48; r <= 57; r++)
				{
				if (((t + r) > (n + i) &&  t >= n) || n < t)
				{
					putchar(n);
					putchar(i);
					putchar(' ');
					putchar(t);
					putchar(r);

					if (n + i + t + r == 227 && n == 57)
					{
					break;
					}
					else
					{
					putchar(',');
					putchar(' ');
					}
				}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
