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
int dp[5][5],a[maxn];
bool c[maxn];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        char x; cin>>x;
        c[i]=(x=='R');
    }

    for(int i=1;i<=n;i++){
        int q=a[i]%2;
        dp[q][c[i]]=max(dp[1-q][1-c[i]]+a[i],dp[q][c[i]]);
    }
    cout<<max({dp[0][1],dp[1][0],dp[1][1],dp[0][0]})<<endl;
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
