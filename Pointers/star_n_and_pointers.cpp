#include<iostream>

using namespace std;

int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int *ptr = arr;
   printf("arr[2] = %d\n", arr[2]);
   printf("*(ptr + 2) = %d\n", *(arr + 2));
   printf("ptr[2] = %d\n", ptr[2]);
   printf("*(ptr + 2) = %d\n", *(ptr + 2));
      printf("ptr[0] = %d\n", ptr[0]);
   printf("*(ptr + 0) = %d\n", *(ptr + 0));
      printf("ptr[1] = %d\n", ptr[1]);
   printf("*(ptr + 1) = %d\n", *(ptr + 1));

   char aarr[6] = "geeks";  // arr[] is not terminated with '\0'
                                   // and its size is 5
  printf("%d", sizeof(aarr));

  return 0;

 getchar();
 return 0;
}
