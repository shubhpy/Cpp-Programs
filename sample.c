/* sample.c */
#include<stdio.h>

int main(int argc, char *argv[])
{
    int j;
    j = argv[1] + argv[2] + argv[3];
    printf("%d", j);
    return 0;
}



What will be the output of the program (sample.c) given below if it is executed from the command line?
cmd> sample friday tuesday sunday
/* sample.c */
#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("%c", **++argv);
    return 0;
}


What will be the output of the program (myprog.c) given below if it is executed from the command line?
cmd> myprog friday tuesday sunday
/* myprog.c */
#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("%c", *++argv[1]);
    return 0;
}
