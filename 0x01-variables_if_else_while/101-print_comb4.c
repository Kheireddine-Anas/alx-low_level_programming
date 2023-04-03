#include <stdio.h>
#include <unistd.h>
/**
 * main - Entyr point
 * Description: prints different combinations of three digits.
 * Return: Always 0 (success)
 */
int main(void)
{
int n, i, t;

for (n = '0'; n <= '9'; n++)
{
	for (i = '0'; i <= '9'; i++)
	{
		for (t = '0'; t <= '9'; t++)
		{
			if (n < i && i < t)
			{
				putchar(n);
				putchar(i);
				putchar(t);
				if (n != '7')
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
}
putchar('\n');
return (0);
}
