#include <stdio.h>
#include <string.h>
int main()
{
    char *s= "geeksquiz";
    printf("%lu", sizeof(s));
    printf("%lu", strlen(s));

     char *str1 = "Sanjeev";
     char str2[] = "Sanjeev";
     printf("%d %d\n",strlen(str1),sizeof(str1));
     printf("%d %d\n",strlen(str2),sizeof(str2));

    // Uncommenting below line would cause undefined behaviour
    // (Caused segmentation fault on gcc)
    //  s[0] = 'j';
    return 0;
}
