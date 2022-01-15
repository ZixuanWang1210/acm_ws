#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;

int N, V;
int dp[maxn];
int w[12010], v[12010];//逐一枚举最大是N*logS

int main(){
    cin >> N >> V;
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        int a, b, s; cin >> a >> b >> s;
        int k = 1;
        while(k <= s){
            v[++cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0){
            v[++cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    N = cnt;

    for(int i = 1; i <= N; i++){
        for(int j = V; j >= v[i]; j--){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V];

    return 0;
}