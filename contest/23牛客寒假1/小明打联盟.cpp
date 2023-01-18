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

const int maxn=1e5+10;
int dp[maxn];
int v[maxn],w[maxn];
int l,r,temp,A;
int t;

void sol(){
    // cin>>t;
    for(int i=1;i<=3;i++) cin>>w[i]>>v[i];
    cin>>l>>r>>temp>>A;
    memset(dp,0,sizeof dp)  ;
    for(int i=0;i<=r-l;i++){
        w[4+i]=i+l;
        v[4+i]=temp+A*i;
    }
    for(int i=1;i<=4+r-l;i++){
        for(int j=w[i];j<=t;j++){
            dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
            // if(j>=l&&j<=r){
            //     dp[j]=max(dp[j],dp[j]+(j-l)*A+temp);
            // }
        }
    }
    cout<<dp[t]<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(cin>>t){
        sol();
    }

    return 0;
}
