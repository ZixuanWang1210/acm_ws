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
const int maxn=1e3+10;
int a[maxn],dp[maxn];
int w[maxn][maxn],v[maxn][maxn];

void sol(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=a[i];j++){
            cin>>v[i][j];
        } 
        for(int j=1;j<=a[i];j++){
            cin>>w[i][j];
        }
    }
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=a[i];k++){
                if(j>=w[i][k])
                    dp[j]=max(dp[j],dp[j-w[i][k]]+v[i][k]);
            }
        }
    }
    cout<<dp[m]<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
