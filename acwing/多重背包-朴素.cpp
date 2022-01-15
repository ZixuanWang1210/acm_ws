#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

int dp[maxn][maxn];
int v[maxn], w[maxn], s[maxn];
int N, V;

int main(){
    cin >> N >> V;
    for(int i = 1; i <= N;i ++) cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= V; j++){
            for(int k = 0; k <= s[i]; k++){
                //dp[i][j] = dp[i - 1][j];
                //区别于01背包，01背包的状态转移过程是非此即彼的，而完全和多重是去最大
                if(j >= k * v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << dp[N][V];
    
    return 0;
}