#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

char a[maxn], b[maxn];
int dp[maxn][maxn];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i] == b[j]) dp[i][j]++;
        }
    }

    cout << dp[n][m];

    return 0;
}