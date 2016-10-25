#include<iostream>
using namespace std;
void times10(int &a)
{
    a=a*10;
    cout<< a << "\n";
}

int main()
{
  int a = 10;
  times10(a);
  cout << a << " \n";
  return 0;
}

