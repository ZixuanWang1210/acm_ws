//https://www.acwing.com/solution/content/1374/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int dp[maxn];
int w[maxn], v[maxn];
int N, V;

int main(){
    cin >> N >> V;
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= N; i++){
        for(int j = V; j >= v[i]; j--){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    } 

    cout << dp[V];

    return 0;
}