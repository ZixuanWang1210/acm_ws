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

int n,m;
const int maxn=2100;
int dp[maxn][maxn];
int a[maxn],b[maxn];
void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]--;
    for(int i=1;i<=m;i++) cin>>b[i],b[i]--;
    memset(dp,0x7f,sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+a[i]*b[j];
        }
    }
    cout<<dp[n][m]<<endl;

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
