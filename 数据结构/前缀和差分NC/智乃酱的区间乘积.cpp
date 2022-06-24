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

int qpow(int a,int b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1) ans=ans*a%mod;
    }
    return ans;
}

const int maxn=1e5+10;
int n,m;
int a[maxn],b[maxn];

void sol(){
    cin>>n>>m;
    b[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=1;
        b[i]=b[i-1]*a[i]%mod;
    }

    while(m--){
        int l,r; cin>>l>>r;
        cout<<b[r]*qpow(b[l-1],mod-2)%mod<<endl;
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
