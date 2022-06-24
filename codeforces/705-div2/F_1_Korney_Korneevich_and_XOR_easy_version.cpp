#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;
int dp[100010];

void sol(){
    int n; cin>>n;
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int w; cin>>w;
        for(int j=0;j<=512;j++){
            if(dp[j]<w) dp[j^w]=min(dp[j^w],w);
        }
    }
    vector<int> ans;
    for(int i=0;i<=512;i++){
        if(dp[i]!=inf) ans.push_back(i);
    }
    sort(_all(ans));
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<endl;

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
