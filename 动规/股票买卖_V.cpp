#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

const int maxn=1e5+10;
int dp[maxn][3];
int n;
int w[maxn];

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    memset(dp,-0x3f,sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-w[i]);
        dp[i][2]=dp[i-1][1]+w[i];
    }
    cout<<max(dp[n][0],dp[n][2]);

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;、
    while(_--){
        sol();
    }

    return 0;
}
