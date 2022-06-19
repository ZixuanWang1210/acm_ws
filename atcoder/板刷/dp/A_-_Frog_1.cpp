#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define ll long long
#define int long long

using namespace std;

const int maxn=3e5+10;
ll dp[maxn];
int h[maxn];
int n;

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];

    dp[1]=0;
    dp[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;i++) dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    cout<<dp[n]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;?
    while(_--){
        sol();
    }

    return 0;
}
