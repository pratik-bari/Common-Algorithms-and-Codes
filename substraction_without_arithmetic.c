#include <stdio.h>

int substract(int x, int y)
{
	while(y != 0)
	{
		int borrow = (~x) & y;
		x = x ^ y;
		y = borrow << 1;
	}

	return x;
}

int main()
{
	int a = 5;
	int b = 28;

	printf("Substraction of %d and %d is %d\n", a, b, substract(a,b));

	return 0;
}
