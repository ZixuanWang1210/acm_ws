#include<bits/stdc++.h>
#define f dp
using namespace std;

int n,m,K;
const int N=1010, M=210, mod=1e9+7;
char a[N],b[N];
int dp[M][M],sum[M][M];

int main(){
    scanf("%d%d%d", &n, &m, &K);
    scanf("%s%s", a + 1, b + 1);

    dp[0][0]=1;
    for (int i = 1; i <= n; i ++ )
        for (int j = m; j; j -- )
            for (int k = K; k; k -- )
            {
                if (a[i] == b[j]) sum[j][k] = (sum[j - 1][k] + f[j - 1][k - 1]) % mod;
                else sum[j][k] = 0;
                f[j][k] = (f[j][k] + sum[j][k]) % mod;
            }

    cout<<dp[m][K];

    return 0;
}