#include<iostream>

using namespace std;

main()
{
   int n, c, first = 0, second = 1, next;

   cin >> n;

   for ( c = 2 ; c < n+1 ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
   }
   cout << second << endl;

   return 0;
}
