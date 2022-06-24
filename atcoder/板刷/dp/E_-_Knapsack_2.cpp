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

const int maxn=1e6+10;
int n,W,V;
int dp[maxn];
int w[maxn],v[maxn];

void sol(){
    cin>>n>>W;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i],V+=v[i];

    memset(dp,0x7f,sizeof dp);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
        }
    }

    for(int i=V;i>=0;i--){
        if(dp[i]<=W){
            cout<<i<<endl;
            return;
        }
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
