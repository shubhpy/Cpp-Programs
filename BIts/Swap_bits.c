#include<stdio.h>

void bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 4; i > 0; i = i / 2){

		(n & i)? printf("1"): printf("0");
	}
	printf("\n");
}

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 =  (x >> p1) & ((1U << n) - 1);
    bin(set1);

    /* Moce all bits of second set to rightmost side */
    unsigned int set2 =  (x >> p2) & ((1U << n) - 1);
    bin(set2);
    /* XOR the two sets */
    unsigned int xor = (set1 ^ set2);
    bin(xor);

    /* Put the xor bits back to their original positions */
    xor = (xor << p1) | (xor << p2);
    bin(xor);

    /* XOR the 'xor' with the original number so that the
       two sets are swapped */
    unsigned int result = x ^ xor;
    bin(result);

    return result;
}

/* Drier program to test above function*/
int main()
{
    int res =  swapBits(28, 0, 3, 2);
    printf("\nResult = %d ", res);
    return 0;
}
