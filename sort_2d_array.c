#include<stdio.h>
#include<stdlib.h>
int main()
{
        int arr[4][2] = {{18,2},{5,3},{10,8},{4,2}};
        int row=4,col=2;
        int i,j,k=0,x,temp;
        for(i=0;i<row;i++)
        {
                for(j=i+1;j<row;j++)
                {
                        if(arr[i][k] > arr[j][k])
                        {
                            for(x=0;x<2;x++) {
                                temp=arr[i][x];
                                arr[i][x]=arr[j][x];
                                arr[j][x]=temp;
                                }
                        }
                }
        }
        for(i=0;i<row;i++)
        {
                for(j=0;j<col;j++)
                printf("%d ", arr[i][j]);
                printf("\n");
        }
}
