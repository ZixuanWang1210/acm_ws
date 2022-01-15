#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int dp[maxn];
int a[maxn];
int n, ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j <= i; j++){
            if(a[j] < a[i]) dp[i] = max(dp[j] + 1, dp[i]);
        }
    }

    for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
    cout << ans;
    
    return 0;
}