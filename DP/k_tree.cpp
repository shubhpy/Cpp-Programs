#include <cstdio>
int n, k, D, d[2][110], M = 1e9 + 7;
main() {
    scanf("%d%d%d", &n, &k, &D);
    d[0][0] = 1;
    for (int S = 1; S <= n; S++){
        for (int N = 1; N <= k && N <= S; N++){
            (d[0][S] += d[0][S - N])%= M;
            (d[1][S] += d[N < D][S - N])%= M;
        }
    }
    printf("%d", d[1][n]);
}
