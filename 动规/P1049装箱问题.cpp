#include <bits/stdc++.h>
using namespace std;
int v[35], w[35], dp[35][20010], vo;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int n;
    cin >> vo >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        //w[i] = v[i];
    }
    memset(dp, 0, sizeof(0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <=vo; j++){
            if(j<w[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+w[i]);
            }
            //if(i == 0 || j == 0) dp[i][j] = 0;
            // if(j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]); 
            // else{
            //     dp[i][j] = dp[i-1][j];
            // }
        }
    }
    cout << vo - dp[n][vo];
    return 0;
}
