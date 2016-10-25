#include<iostream>
using namespace std;
int main()
{
  int a[2][2]= { {1, 2}, {3, 4}};
  cout << a[0][0] << "\n";
   cout << a[0][1] << "\n";

cout << a[1][0] << "\n";

   cout << a[1][1] << "\n";

   // Works
  printf("%d", sizeof(a)); // prints 8*sizeof(int)
  getchar();
  return 0;
}

        for(int q_i = 0;q_i < n;q_i++){
            cout << a[q_i][0] << " " << a[q_i][1] << " \n";
        }
