#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int *p;

    p = (int *)malloc(sizeof(int)*2);

    *p = 10;
    *(p+1) = 20;
    p = (int *)realloc(p,sizeof(int)*3);

    *(p+2) = 30;

    for(int i=0;i<3;i++){
        cout << *(p + i) << " ";
        }
    free(p);
}
