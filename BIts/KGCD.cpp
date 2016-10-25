#include <iostream>

using namespace std;
long long kgcd(long long a, long long b)
{
    long long t;
    while (a > 0 && b > 0)
    {
        a -= b;
        t = a;
        a = b;
        b = t;
    }
    return a + b;
}

long long gcd(long long a, long long b)
{
    long long t;
    if (a<b){
        while(a!=0){
            t = a;
            a = b%a;
            b = t;
        }
        return b;
    }
    else{
        while(b!=0){
            t = b;
            b = a%b;
            a = t;
        }
        return a;
    }
}

int main()
{
	int T;
	cin >> T;
	long long int N;
	for(int i= 0;i<T;i++){
        cin >> N;
        long long int sum ;
        sum = N*N;
        for(int j = 2;j<N;j++){
            if (N%j==0){
                sum  = sum - (N/j) + 1;
            }
            else{
                sum  = sum - (N/j);
            }
        }

        int count = 0;
        for(int i  = 1;i<=N;i++){
            for(int j = 1 ;j<=N;j++){
                if (kgcd(i,j)==gcd(i,j))
                        count++;
                else
                    cout << i << " " << j << "\n";
            }
        }

        cout << sum <<  " " <<  count << "\n";
	}
	return 0;
}
