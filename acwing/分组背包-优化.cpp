#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

int dp[maxn];
int N, V;
int v[maxn][maxn], w[maxn][maxn], s[maxn];

int main(){
    cin >> N >> V;
    for(int i = 1; i <= N; i++){
        cin >> s[i];
        for(int j = 0; j < s[i]; j++){
            cin >> v[i][j] >> w[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = V; j >= 0; j--){
            for(int k = 0; k < s[i]; k++){
                if(v[i][k] <= j) dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
            }
        }
    }

    cout << dp[V];

    return 0;
}