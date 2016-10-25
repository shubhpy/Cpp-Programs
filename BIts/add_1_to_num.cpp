#include<stdio.h>

void bin(unsigned n){

    unsigned int i;
    for(i = 1<<5;i>0;i=i/2){
        if (n&i){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");

    }

int addOne(int x)
{
  int m = 1;

  /* Flip all the set bits until we find a 0 */
  bin(x&m);
  while( x & m )
  {
    bin(x&m);
    x = x^m;
    bin(x);
    m <<= 1;
    bin(m);
  }

  /* flip the rightmost 0 bit */
  x = x^m;
  return x;
}

/* Driver program to test above functions*/
int main()
{
  printf("%d", addOne(15));
  getchar();
  return 0;
}
