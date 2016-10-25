
#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    int count = 0;
    int i;
    for(i=1;i<=n;i++){
        int t = i;
        while(t){
            t = t&(t-1);
            count++;
        }
    }

    printf("%d",count);
    return 0;

    }
