#include <bits/stdc++.h>

using namespace std;

int t, m;
int w[105], v[105];
int dp[105][1010];


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif


    cin >> t >> m;
    for(int i = 1; i <= m; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= t; j++){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[m][t];
    return 0;
}
