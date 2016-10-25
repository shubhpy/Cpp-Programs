#include<stdio.h>

void swap(char **str1)
{
      printf("%s \n",str1);
  printf("%c \n",*str1);
  printf("%c \n",**str1);
  printf("%p \n",&str1);
}

int main()
{
  char *str1 = "geeks";
  //char *str2 = "forgeeks";
  printf("%s \n",str1);
  printf("%c \n",*str1);
  printf("%p \n",&str1);
  swap(&str1);

  int * j= 3432;
  printf("%d \n",j);
    printf("%p \n",&j);
  printf("%d \n",*j);

  //printf("in main str1 is %s, str2 is %s", str1, str2);
  return 0;
}
