#include <stdio.h>
#include<math.h>

#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))
#define PrintDigit(c, d) for(i=0; i < c ; i++)putchar(unit[d]);
#define forn(a,n) for(i=a; i < n ; i++);

int* solve(){
    int x[6];

    a = a & K;
    pa = (((float)A)*pa)/100;
    b = b | K;
    pb = (((float)B)*pb)/100;
    c = c ^ K;
    pc = (((float)C)*pc)/100;

    x[0] = a;
    x[1] = b;
    x[2] = c;

    return x;
    }

int main()
    {
        int* x;
        x = solve();
        printf("%d",x[0]);
        /*
        LL T;
        scanf("%lld",&T);
        for (int i=0;i<T;i++){
            LL N,X,K;
            LL A,B,C;
            LL a,b,c;
            long double pa=1,pb=1,pc=1;
            scanf("%lld",&N);
            scanf("%lld",&X);
            scanf("%lld",&K);
            scanf("%lld",&A);
            scanf("%lld",&B);
            scanf("%lld",&C);
            a=X;
            b=X;
            c=X;
            //cin >> N >> X >> K >> A >> B >> C;
            printf("%lld %lld %lld  %Lf %Lf %Lf\n",a,b,c,pa,pb,pc);

            for(int j=0;j<N;j++){
                a = a & K;
                pa = (((float)A)*pa)/100;
                b = b | K;
                pb = (((float)B)*pb)/100;
                c = c ^ K;
                pc = (((float)C)*pc)/100;

                printf("%lld %lld %lld  %Lf %Lf %Lf\n",a,b,c,pa,pb,pc);
            }

printf("%Lf \n",a*pa + b*pb + c*pc);
        }
*/

       return 0;
    }
