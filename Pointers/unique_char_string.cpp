#include <stdio.h>
#include <limits.h>
/**
 * Assumes target is large enough to hold the result.
 */
char *stripDuplicates(const char *src, char *target)
{
  int lookup[SCHAR_MAX] = {0};
  char *t = target; // save original pointer to return
  while(*src != 0)
  {
    if (!lookup[*src])
    {
      *t++ = *src;
      lookup[*src] = 1;
    }
    src++;
  }
  *t++ = 0;
  return target;
}

int main(void)
{
  char *source = "koko";
  char target[30];
  printf("%s => %s", source, stripDuplicates(source, target));
  return 0;
}
 char ascii;
 cout << "Enter a character: ";
 cin >> ascii;
 cout << "Its ascii value is: " << (int) ascii << endl;
