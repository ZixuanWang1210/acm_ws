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
int n,k;

void sol(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>h[i];

    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(k,i-1);j++){
            dp[i]=min(dp[i-j]+abs(h[i]-h[i-j]),dp[i]);
        }
    }
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
