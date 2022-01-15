//https://www.acwing.com/solution/content/3986/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int dp[maxn];
int N, V;
int v[maxn], w[maxn];

int main(){
    cin >> N >> V;
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= N; i++){
        for(int j = v[i]; j <= V; j++){ //唯一区别!!循环顺序
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]); //区别01背包的空间优化
                                                     //完全背包一个物品可以取无限次
        }
    }

    cout << dp[V];

    return 0;
}