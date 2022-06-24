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
int n;
int w[maxn],v[maxn];
int W;

void sol(){
    cin>>n>>W;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];

    for(int i=1;i<=n;i++){
        for(int j=W;j>=w[i];j--){
            dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
        }
    }
    cout<<dp[W]<<endl;

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
