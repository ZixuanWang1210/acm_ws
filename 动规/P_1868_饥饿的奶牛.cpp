
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
vector<int> v[maxn]; 
int n, mx, dp[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
    //      int st=0x3f3f3f3f,ed=-0x3f3f3f3f;
    // for(int i=1;i<=n;i++){
    //     int p,t; cin>>p>>t;
    //     v[p].push_back(t-p);
    //     st=min(st,p),ed=max(ed,t);
    // }
        v[y].push_back(x - 1);
        mx = max(mx, y);
    }
    for (int i = 1; i <= mx; i++) {
        dp[i] = dp[i - 1];
        // for (int j = 0; j < v[i].size(); j++) {
        //     int b = v[i][j];
        //     dp[i] = max(dp[i], dp[b] + i - b);
        // }
        for(auto x:v[i]){
            dp[i]=max(dp[i],dp[x]+i-x);
        }
    }
    // for (int i = 1; i <= mx; i++) {
    //     cout << dp[i] << ' ';
    // }
    printf("%d\n", dp[mx]);
    return 0;
}