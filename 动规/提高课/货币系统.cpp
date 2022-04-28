#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e4+10;
long long dp[maxn];

void sol(){
    int n,m; cin>>n>>m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            dp[j]+=dp[j-v[i]];
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
