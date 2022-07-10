#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=3e3+10;
int dp[maxn][maxn];
int dp2[maxn][maxn];
int n;
int W[maxn],T[maxn];

void sol(){
    cin>>n;
    int q; cin>>q;
    for(int i=1;i<=n;i++){
        cin>>W[i]>>T[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-W[i]]+T[i]);
        }
    }
    
    while(q--){
        int x,y; cin>>x>>y;

    }

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
