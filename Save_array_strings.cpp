#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
  char eAddress[80] = {};

  // Prompt user for an email address
  cout << "Email Address? " << endl;
  cin.getline(eAddress, 80);
  cout << eAddress << endl;

  cout << eAddress[5];

  system("pause");
  return 0;
}
