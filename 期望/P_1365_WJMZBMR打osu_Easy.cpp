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

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    double p[n+1];
    for(int i=1;i<=n;i++){
        if(s[i-1]=='o') p[i]=1.0;
        else if(s[i-1]=='x') p[i]=0.0;
        else p[i]=0.5;
    }
    double  dp[n+1],x[n+1];
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+(x[i-1]*2+1.0)*p[i];
        x[i]=(x[i-1]+1.0)*p[i];
    }
    cout<<fixed<<setprecision(4)<<dp[n]<<endl;

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
