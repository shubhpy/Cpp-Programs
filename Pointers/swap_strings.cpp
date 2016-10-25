#include<iostream>
#include<string.h>
using namespace std;
void swap(string *str1, string *str2)
{

  string temp = *str1;
  *str1 = *str2;
  *str2 = temp;

  cout << *str1 << " " << *str2 << "\n";
}

int main()
{
  string str1 = "geeks";
  string str2 = "forgeeks";
cout << str1 << " " << str2 << "\n";
  swap(&str1,&str2);
cout << str1 << " " << str2 << "\n";


  //printf("in main str1 is %s, str2 is %s", str1, str2);
  getchar();
  return 0;
}
