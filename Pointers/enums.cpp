#include <stdio.h>
enum State {Working = 1, Failed = 0, Freezed = 0};
//enum day {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
enum day {sunday = 1, monday, tuesday = 5,
          wednesday, thursday, friday, saturday};
int main()
{
   printf("%d, %d, %d \n", Working, Failed, Freezed);
   printf("%d \n", thursday);
   return 0;
}
