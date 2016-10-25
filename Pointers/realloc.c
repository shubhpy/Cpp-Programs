#include<stdio.h>

int main()
{
    int *p;

    p = (int *)malloc(sizeof(int)*2);

    *p = 10;
    *(p+1) = 20;


    *(p+2) = 30;
    int i;
    for(i=0;i<3;i++){
        printf("%d \n",*(p + i));
        }

    free(p);

}
