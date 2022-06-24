#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define ll long long
// #define int long long

using namespace std;

const int maxn=1e5+10;
int n,m;
int a[maxn];
int s[maxn];

int qpow(int a,int b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1) ans=ans*a%mod;
    }
}

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];




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
