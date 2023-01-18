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

const int maxn=1e5+10;
int dp[maxn];
int a[maxn];

void sol(){
    int n,k,w; cin>>n>>k>>w;
    memset(dp,-0x3f,sizeof dp);
    dp[0]=0;
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        a[i]-=a[0];
    } 
    w-=k;
    for(int i=1;i<n;i++){
        for(int j=i;j<=w;j++){
            dp[j]=max(dp[j-i]+a[i],dp[j]);
        }
    }
    cout<<dp[w]+k*a[0]<<endl;
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
