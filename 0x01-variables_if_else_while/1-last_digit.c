#include <stdlib.h>
#include <time.h>
/* C file creadted by KHEIREDDINE*/

/* if and else if : for checking n if it greater than 5*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf("Last digit of %d is %d", n, n);
    if (n > 5)
	{
		printf(" and is greater than 5\n");
	}
	else if (n < 6)
	{
		printf(" and is less than 6 and not 0\n");
	}
    else
    {
		printf(" and is 0\n");
    }
	return (0);
}
