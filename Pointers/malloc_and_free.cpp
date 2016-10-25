#include<iostream>
#include<string.h>

using namespace std;

int main()
{
     //1
     int *p;

    p=(int *)malloc(sizeof(int));

    if (p==NULL){
    cout<<"Falied";
    }
    else{
    *p=20;
    cout << *p;
    free(p);
    }




    //2
    char *ptr;
    int length = 5;

    ptr = (char * )(malloc(sizeof(char)*length + 1));
    if (ptr==NULL){
    cout<<"Falied";
    }
    else{
    cin >> ptr;
    cout << ptr;
    cout << &ptr;
    free(ptr);
    }


//3


    int *pt;

    pt=(int *)calloc(5,sizeof(int));

    for(int i=0;i<5;i++){
        cout<< pt[i] << " ";
            }
    //Initialised with zero

    if (pt==NULL){
    cout<<"Falied";
    }
    else{
        for(int i=0;i<5;i++){
            cin>>pt[i];
            }

        for(int i=0;i<5;i++){
            cout<< pt[i] << " ";
            }
    free(pt);
    }

//4

    //realloc function
    char *ptrr;
    ptrr= (char *)malloc(5);
    strcpy(ptrr,"Hel");
    cout << ptrr << "\n";
    ptrr = (char *)realloc(ptrr,8);
    strcat(ptrr,"lo");
    cout << ptrr;

    free(ptrr);

    //make a new allocated memory and copy data from old to new and free the old


    /*

    void *realloc(void *ptr, size_t size);

    void *realloc(void *ptr, size_t size=0) = free(void *ptr)

    oid *realloc(void *ptr = NULL, size_t size) = void *malloc(size_t size)


    */

    /* using malloc and memset to get the functionality of calloc

    void *calloc(size_t num, size_t size); =====

    ptr = void * malloc(size_t size);
    memset(ptr,num,size);


    */

    }
