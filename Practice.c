#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;

     pid = fork();
     if (pid == 0)
          ChildProcess();
     else
          ParentProcess();
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
}

/*#include  <stdio.h>
#include  <sys/types.h>
int main(){
    //int count = 0;
    fork();
   fork() && fork() || fork();
   fork();
   //count++;
   printf("forked\n");
   //printf("%d\n",count);
   return 0;

    /*int a;
    if (fork() == 0){
        a = a + 5; printf("%d,%d\n", a, &a); }
    else {
        a = a- 5; printf("%d, %d\n", a, &a); }

}
*/
/*int main()
{
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}
*/
/*#include<stdio.h>

int main()
{
    char str[20] = "Hello";
    char *const p=str;
    *(p+1)='M';
    printf("%s\n", str);
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    char *p1 = "India", *p2;
    p2=p1;
    p1 = "BIX";
    fprintf(stdout,"%s %s\n",p1,p2);
    return 0;
}
*/
