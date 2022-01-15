#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10, INF = 0x3f3f3f3f;

int dp[maxn][maxn], a[maxn][maxn];
int n, ans = -INF;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i + 1; j++){
            if(j == 0 || j == i + 1){
                dp[i][j] = -INF;
                continue;
            }
            cin >> a[i][j];
            dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i - 1][j - 1] + a[i][j]);
            if(i == n)
                ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;


    return 0;
}