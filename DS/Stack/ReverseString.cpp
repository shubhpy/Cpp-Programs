#include<iostream>
#include<string.h>

using namespace std;

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned Capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack*));
    stack->top = -1;
    stack->capacity = Capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
    }

void push(struct Stack* stack,int item){
    stack->array[++stack->top] = item;
    }

int pop(struct Stack* stack){
    return stack->array[stack->top--];
    }

void Reverse(char str[]){

    struct Stack* stack = createStack(100);

    int n = strlen(str);
    for (int i=0;i<n;i++){
        push(stack,str[i]);
        }
    for (int i=0;i<n;i++){
        str[i]=pop(stack);
        }
    }


int main(){

    char str[] = "GeeksQuiz";
    Reverse(str);

    cout << str;


    }
