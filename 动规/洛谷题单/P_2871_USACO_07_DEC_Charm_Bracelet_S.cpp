#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e6+10;
int dp[maxn];
int n,m;
int w[maxn],v[maxn];

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];

    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
