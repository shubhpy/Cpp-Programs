#include<iostream>

using namespace std;

int main(){

    char arr[] = "abc";
    int *i = 5;
     //sets the first four elements in array to ‘a’, ‘b’, ‘c’, and ‘\0′
    char *p = "abc";
    //sets pointer to the address of the “abc” string (which may be stored in read-only memory and thus unchangeable


    cout<< sizeof(arr)<< " \n";
    cout<< sizeof(arr)/sizeof(*arr)<< " \n";
    cout<< &arr<< " \n";
    cout<< &(arr[0])<< " \n";
    cout<< sizeof(p)<< " \n";
    cout<< sizeof(p)/sizeof(*p)<< " \n";
    cout<< &p<< " \n";
    cout<< *p++<< " \n";
    cout<< *p<< " \n";
    cout<< *p++<< " \n";
    cout<< *p<< " \n";
    cout<< *p++<< " \n";
    cout<< *p<< " \n";
    }
