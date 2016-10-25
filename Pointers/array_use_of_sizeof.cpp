#include<iostream>

using namespace std;

void fun(int arr[])
{
  int i;

  /* sizeof should not be used here to get number
    of elements in array*/
    cout << sizeof(arr) << " \n";
    cout << sizeof(arr[0]) << " \n";
  int arr_size = sizeof(arr)/sizeof(arr[0]); /* incorrect use of siseof*/
      cout << arr_size<< " \n";
  for (i = 0; i < arr_size; i++)
  {
    arr[i] = 1;  /*executed only once */
  }
}

int main()
{
  int i;
  int arr[4] = {0, 0 ,0, 0};
    cout << sizeof(arr) << " \n";
    cout << sizeof(arr[0]) << " \n";

  fun(arr);

  /* use of sizeof is fine here*/
  for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    printf(" %d " ,arr[i]);

  getchar();
  return 0;


}
