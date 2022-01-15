#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int dp[maxn][maxn] {}, s1[maxn] {}, s2[maxn] {}, n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n;
    for(int j = 1; j <= n; j++) cin >> s1[j];
    for(int j = 1; j <= n; j++) cin >> s2[j];
        
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s1[j]==s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][n];
    return 0;
}
