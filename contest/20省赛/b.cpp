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
int dp[maxn];
int n,m;
int d[maxn],p[maxn];
int a[maxn];


void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>d[i];

    int idx=0;
    for(int l=1,r;l<=m;l=r+1){
        r=m/(m/l);
        a[++idx]=r;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=idx;j++){
            int q=a[j];
            dp[q/d[i]]=max(dp[q]+p[i]*q,dp[q/d[i]]);
        }
    }
    int ans=0;
    for(int i=0;i<=idx;i++) ans=max(ans,dp[a[i]]);
    cout<<ans<<endl;
    return ;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;1
    while(_--){
        sol();
    }

    return 0;
}
