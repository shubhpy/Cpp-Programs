#include<iostream>

using namespace std;

// A variable declaration like basic data types
struct Point
{
   int x, y,z;
} p1;

typedef struct
    {
        int age;
    }person ;

int main()
{
    p1 = {0, 1}; // The variable p1 is declared like a normal variable
    // struct keyword is optional
    //p1.x = 20;
    cout << p1.x  << "  " << p1.y << " " << p1.z <<endl;

    person var = {23};

    cout << var.age << "\n";

/* FEATURE ONLY IN C not in C++

    // Examples of initializtion using designated initialization
   struct Point p2 = {.y = 0, .z = 1, .x = 2};
   struct Point p3 = {.x = 20};

   printf ("x = %d, y = %d, z = %d\n", p2.x, p2.y, p2.z);
   printf ("x = %d", p3.x);

   */

   struct Point arr[10];

   // Access array members
   arr[0].x = 10;
   arr[0].y = 20;

   printf("%d %d \n", arr[0].x, arr[0].y);

   // p3 is a pointer to structure p1
   struct Point *p3 = &p1;

   // Accessing structure members using structure pointer
   printf("%d %d", p3->x, p3->y);


    }
