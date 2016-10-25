#include<stdio.h>

void bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 31; i > 0; i = i / 2){

		(n & i)? printf("1"): printf("0");
	}
}

int main()
{
	int n;
	unsigned i;
	scanf("%d",&n);

	//bin((1U << 2)-1);

	bin(n);
/*
	printf("\n%d\n",10<<5);
	printf("\n%d\n",10>>5);


	while(0){
        bin(n);
        printf("\n");
        n--;

	}

	for(i=0;i<50;i++)
        //printf("%d\n", 1L << i);
        printf("\nNegation of Number %d : %d\n",i,~i);
*/
	return 0;
}
