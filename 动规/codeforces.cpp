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

const int maxn=100;
struct node{
    int v,w;
    int t;
    bool operator<(const node &tt) const{
        return t*tt.w<tt.t*w;
    }
} a[maxn];
int n,T;
int dp[100005];

void sol(){
    cin>>n>>T;
    for(int i=1;i<=n;i++) cin>>a[i].v;
    for(int i=1;i<=n;i++) cin>>a[i].w;
    for(int i=1;i<=n;i++) cin>>a[i].t;

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        for(int j=T;j>=a[i].t;j--){
            dp[j]=max(dp[j],dp[j-a[i].t]+a[i].v-j*a[i].w);
        }
    }

    int ans=0;
    for(int i=T;i>=0;i--) ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return;
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
