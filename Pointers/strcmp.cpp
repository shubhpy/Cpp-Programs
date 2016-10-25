#include<stdio.h>
/* my_strcmp(a, b) returns 0 if strings a and b are same, otherwise 1.
 It recursively increases a and b pointers.
 At any point if *a is not equal to *b then 1 is returned.
If we reach end of both strings at the same time then 0 is returned. */
int my_strcmp(char *a, char *b)
{
    printf("%c  %c  \n",*a,*b);
  return (*a == *b && *b == '\0')? 0 : (*a == *b)? my_strcmp(++a, ++b): 1;
}

/* driver function to test above function */
int main()
{
  char *a = "geeksforgeeks";
  char *b = "geeksforgeeks";
  if(my_strcmp(a, b) == 0)
     printf(" String are same ");
  else
     printf(" String are not same ");

  getchar();
  return 0;
}
