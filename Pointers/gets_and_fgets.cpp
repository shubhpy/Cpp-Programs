#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 4

void read_gets()
{
   char str[4];
   gets(str);
   /*#cannot have more than 8 bcoz the datatype char can only have 8 FAILS
   */
   printf("%s \n", str);
   return;
}

void read_fgets()
{
   char str[MAX_LIMIT];
   fgets(str, MAX_LIMIT+1, stdin);
   /*#need to add 1 to MAX_LIMIT
   */
   printf("%s", str);

   getchar();
   return;
}

int main(){
read_gets();
read_fgets();
}
