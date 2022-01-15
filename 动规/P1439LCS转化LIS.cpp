#include <bits/stdc++.h>
using namespace std;

int s1[100010], s2[100010], dp[100010];
map<int, int>mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int n, ans = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s1[i];
    for(int i = 1; i <= n; i++) cin >> s2[i];
    for(int i = 1; i <= n; i++) mp[s1[i]] = i;
    for(int i = 1; i <= n; i++) s2[i] = mp[s2[i]];
    
    dp[1] = 1, dp[0] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j <= i; j++){
            if(dp[i] >= dp[j]) dp[i] = max(dp[j]+1, dp[i]); 
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}
