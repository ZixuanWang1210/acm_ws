#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define ll long long
#define int long long
#define mod 1000000007
using namespace std;

const int maxn=5e6+10;
ll fac[maxn],infac[maxn];
int n,r1,r2,r,a,h; 

int q_mi(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1) ans=ans*a%mod;
    }
    return ans;
}

void init(){
    fac[0]=infac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
        infac[i]=infac[i-1]*q_mi(i,mod-2)%mod;
    }
}

ll C(ll n,ll m){
    if(n<m){
        return 0;
    }
    return fac[n]*infac[m]%mod*infac[n-m]%mod;
}

void sol(){
    cin>>n;
    init();
        // cout<<C(2,1)<<endl;
    cin>>n>>r1>>r2>>r>>a>>h;
    ll k=((h-1)/a)+1;
    if(k>n){
        cout<<0<<endl;
        return;
    }
    else if(r1+r>=r2){
        cout<<1<<endl;
        return;
    }

    ll p_x=q_mi(r2*r2,mod-2);
    ll p_s=(r1+r)*(r1+r)%mod;
    ll p=p_x*p_s%mod;

    ll q=(r2 * r2 % mod - (r1 + r) * (r1 + r) % mod + mod) % mod * p_x % mod;

    ll pp=q_mi(p,k),qq=q_mi(q,n-k);

    ll ans=0;
    for(int i=k;i<=n;i++){
        ans=(ans+C(n,i)*pp%mod*qq%mod)%mod;
        pp=pp*p%mod;
        qq=qq*q_mi(q,mod-2)%mod;
    }
    cout<<ans<<endl;

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
