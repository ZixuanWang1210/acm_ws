#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int dp[maxn][maxn];
int N, V;
int w[maxn], v[maxn];

int main(){
    cin >> N >> V;
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= V; j++){
            for(int k = 0; k * v[i] <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }

    cout << dp[N][V];

    return 0;
}