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
int isEmpty(struct Stack* stack){
       return stack->top == -1;
       }

void push(struct Stack* stack,int item){
    stack->array[++stack->top] = item;
    }

int pop(struct Stack* stack){
    return stack->array[stack->top--];
    }

int top(struct Stack* stack){
    return stack->array[stack->top];
    }

void print(struct Stack* stack){
    if (isEmpty(stack)){
        return ;
    }
    else{
        cout << pop(stack) << " ";
        print(stack);
    }
}

int fun(struct Stack* stack,int item,bool rec){
    if (isEmpty(stack)){
            if (!rec){
                push(stack,item);
            }
            return 1;
    }
    else{
            int y = top(stack);
            if (y>=item){
            if (!rec){
                push(stack,item);
            }
                return 1;
            }
            else{
                y = pop(stack);
                int count = 1+fun(stack,item,true);
                push(stack,y);
                    if (!rec){
                        push(stack,item);
                    }
                return count;
            }
    }
}

int main(){

    int T,N,C;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        struct Stack* stack = createStack(N);
        for(int j=0;j<N;j++){
            cin>>C;
            cout << fun(stack,C,false) << " ";
        }
        cout << "\n";
        //print(stack);
    }

    }

 /*Wrong !! The first test case where your code failed:
 Input:
 134
 74 665 742 512 254 469 748 445 663 758 38 60 724 142 330 779 317 636 591 243 289 507 241 143 65 249 247 606 691 330 371 151 607 702 394 349 430 624 85 755 357 641 167 177 332 709 145 440 627 124 738 739 119 483 530 542 34 716 640 59 305 331 378 707 474 787 222 746 525 673 671 230 378 374 298 513 787 491 362 237 756 768 456 375 32 53 151 351 142 125 367 231 708 592 408 138 258 288 554 784 546 110 210 159 222 189 23 147 307 231 414 369 101 592 363 56 611 760 425 538 749 84 396 42 403 351 692 437 575 621 597 22 149 800
 Its Correct output is:
1 2 3 1 1 2 7 1 2 10 1 2 3 1 2 16 1 2 1 1 2 3 1 1 1 4 1 10 13 1 2 1 4 18 1 1 3 4 1 24 1 2 1 2 3 6 1 2 3 1 11 12 1 2 3 4 1 6 1 1 2 3 4 6 1 66 1 2 1 2 1 1 2 1 1 5 77 1 1 1 4 5 1 1 1 2 3 4 1 1 7 1 11 1 1 1 2 3 5 23 1 1 2 1 4 1 1 2 8 1 10 1 1 14 1 1 17 18 1 2 3 1 2 1 4 1 6 1 2 3 1 1 2 134
1 2 3 1 1 2 7 1 2 10 1 2 3 1 2 16 1 2 1 1 2 3 1 1 1 4 1 10 13 1 2 1 4 18 1 1 3 4 1 24 1 2 1 2 3 6 1 2 3 1 11 12 1 2 3 4 1 6 1 1 2 3 4 6 1 66 1 2 1 2 1 1 2 1 1 5 11 1 1 1 4 5 1 1 1 2 3 4 1 1 7 1 11 1 1 1 2 3 5 23 1 1 2 1 4 1 1 2 8 1 10 1 1 14 1 1 17 18 1 2 3 1 2 1 4 1 6 1 2 3 1 1 2 134
*/
