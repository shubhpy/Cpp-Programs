#include<stdio.h>

/* Function to get no of set bits in binary
   representation of passed binary no. */
int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}



/* Program to test function countSetBits */
int main()
{
    int i = 9;
    printf("%d", countSetBits(-2));
    //cout << __builtin_popcount (4) << endl;
    /*Count the bits to be flipped to convert A to B*/
    int A=9;
    int B= 10;
    int ans  = countSetBits(A^B);


    getchar();
    return 0;
}
