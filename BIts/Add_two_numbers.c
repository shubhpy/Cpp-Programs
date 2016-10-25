#include<stdio.h>
void bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 4; i > 0; i = i / 2){

		(n & i)? printf("1"): printf("0");
	}
	printf("\n");
}

int Add(int x, int y)
{
	// Iterate till there is no carry
	while (y != 0)
	{
		// carry now contains common set bits of x and y
		int carry = x & y;
		bin(carry);

		// Sum of bits of x and y where at least one of the bits is not set
		x = x ^ y;
		bin(x);

		// Carry is shifted by one so that adding it to x gives the required sum
		y = carry << 1;
		bin(y);
		printf("\n");
	}
	return x;
}

int main()
{
	printf("%d", Add(5, 3));
	return 0;
}
