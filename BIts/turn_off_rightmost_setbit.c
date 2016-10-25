#include<stdio.h>

int main(){

    int n = 15;
    /*
    int m = 1;
    int count = 0;
    while(!(n&m)){
        n = n >> 1;
        count++;
    }
    n = n>>1;
    count++;
    n = n << count;
    printf("%d",n);

    //OR
    */
    //printf("%d",n&(n-1));
    int k=3;

    printf("%d\n",~(1 << (k - 1)));

    printf("%d",(n & ~(1 << (k - 1))));

    return 0;
    }
