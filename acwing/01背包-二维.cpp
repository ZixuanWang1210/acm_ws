#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int dp[maxn][maxn];
int v[maxn], w[maxn];
int N, V;

int main(){
    cin >> N >> V;
    for(int i = 1; i <= N; i++){
        cin >> v[i] >> w[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= V; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }


    cout << dp[N][V];

    return 0;
}