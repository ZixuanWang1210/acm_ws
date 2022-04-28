#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=2e5+10;
bool st[maxn];
int dp[maxn];

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v.begin()+1,v.begin()+1+n);

    memset(dp,0,sizeof dp);
    dp[0]=1;
    int ans=0;

    for(int i=1;i<=n;i++){
        if(dp[v[i]]) continue;
        ans++;
        for(int j=v[i];j<=v[n];j++){
            dp[j]|=dp[j-v[i]];
        }
    }

    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
