#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Fxy(float x,float y);

int main()
{
    int i;
    float X[100],Y[100],temp,Yg,Yp,Yc,h;
    X[0]=0,Y[0]=1,h=0.2;

    for (i=1;i<4;i++)
    {
        X[i]=X[0]+i*h;

        temp = Fxy(X[i-1],Y[i-1]);
        Yg= Y[i-1]+ h*temp;
        Yp= Y[i-1] + (h/2)*(temp+ Fxy(X[i],Yg));
        Yc = Y[i-1] + (h/2)*(temp+ Fxy(X[i],Yp));

        while( fabs(Yp-Yc) > 0.00001)
            {
            Yp=Yc;
            Yc = Y[i-1] + (h/2)*(temp+ Fxy(X[i],Yp));
            }
        Y[i]=Yc;

        printf(" %f  --  %f \n",X[i],Y[i]);

        }

        for (i=3;i<3+3;i++)
    {
        X[i+1]=X[0]+(i+1)*h;

        Yp= Y[i-3] + (4*h/3)*( 2*Fxy(X[i-2],Y[i-2]) - Fxy(X[i-1],Y[i-1]) + 2*Fxy(X[i],Y[i]) );
        Yc= Y[i-1] + (h/3)*( Fxy(X[i-1],Y[i-1])  + 4*Fxy(X[i],Y[i]) + Fxy(X[i+1],Yp) );

        while( fabs(Yp-Yc) > 0.00001)
            {
            Yp=Yc;
            Yc= Y[i-1] + (h/3)*( Fxy(X[i-1],Y[i-1])  + 4*Fxy(X[i],Y[i]) + Fxy(X[i+1],Yp));
            }
        Y[i+1]=Yc;

        printf(" %f  --  %f \n",X[i+1],Y[i+1]);

        }

return 0;

}

float Fxy(float x,float y){

    return (1+x*x)*y;
}
