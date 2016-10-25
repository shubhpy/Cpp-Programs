#include <stdio.h>

// A simple representation of date
struct date
{
   unsigned int d;
   unsigned int m;
   unsigned int y;
};

// A space optimized representation of date
struct date1
{
   // d has value between 1 and 31, so 5 bits
   // are sufficient
   unsigned int d: 5;

   // m has value between 1 and 12, so 4 bits
   // are sufficient
   unsigned int m: 4;

   unsigned int y;
};

int main()
{
   printf("Size of date is %d bytes\n", sizeof(struct date));
   struct date dt = {31, 12, 2014};
   printf("Date is %d/%d/%d  \n", dt.d, dt.m, dt.y);

   printf("Size of date is %d bytes\n", sizeof(struct date1));
   struct date1 dt1 = {31, 12, 2014};
   printf("Date is %d/%d/%d  \n", dt1.d, dt1.m, dt1.y);

}
