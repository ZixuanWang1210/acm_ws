#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=2e5+10;
int dp[maxn][3];

void sol(){
    int n; cin>>n;
    vector<int> v(n+2);

    for(int i=1;i<=n;i++)
        cin>>v[i];

    dp[1][1]=0,dp[1][0]=0;
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+v[i-1]-1);
        dp[i][1]=max(dp[i-1][0]+v[i]-1,dp[i-1][1]+abs(v[i]-v[i-1]));
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
