#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

const int maxn=2e5+10;
int a[maxn],b[maxn],c[maxn];
int dp[maxn][4];
int n;

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];

    for(int i=1;i<=n;i++){
        dp[i][1]=max(dp[i-1][2],dp[i-1][3])+a[i];
        dp[i][2]=max(dp[i-1][1],dp[i-1][3])+b[i];
        dp[i][3]=max(dp[i-1][2],dp[i-1][1])+c[i];
    }

    cout<<max({dp[n][1],dp[n][2],dp[n][3]})<<endl;
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
