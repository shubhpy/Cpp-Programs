/*
1. Always initialize pointer variables as NULL.
2. Always perform NULL check before accessing any pointer.

*/
#include<stdio.h>
int main()
{
 int *i, *j;
 int *ii = NULL, *jj = NULL;
 if(i == j)
 {
  printf("This might get printed if both i and j are same by chance.");
 }
 if(ii == jj)
 {
  printf("This is always printed coz ii and jj are same. \n");
 }

 printf("%d \n",NULL);
 printf("%s \n",NULL);
 printf("%c \n",NULL);
 printf("%f \n",NULL);
 printf("The pointer size of my platform  =  %d \n",sizeof(NULL));

 //int * ptr = NULL;
 //printf("%d",*ptr); segmentation fault


 printf("%d \n",sizeof(void));

 printf("%d \n",sizeof(void *));
 return 0;
}
