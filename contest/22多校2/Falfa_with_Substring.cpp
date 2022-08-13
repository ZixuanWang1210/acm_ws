#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353
#define ll long long
// #define int long long
using namespace std;

const int N=1e6+10;
ll fac[N],infac[N];
ll qpow(ll a, ll b)
{
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ans = ans * a % mod;
    return ans;
}
void init(int n)
{
    fac[0]=infac[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        infac[i]=infac[i - 1] * qpow(i,mod-2)%mod;
    }
}
ll C(ll m, ll n)	
{
    if (n < m)
        return 0;
    return fac[n] * infac[m] % mod * infac[n - m] % mod;
}

void sol(){
    int n; cin>>n;
    init(n);
    int cnt_bit=n/3;
    cout<<(qpow(26,n)-1)%mod<<' ';
    for(int i=1;i<=n;i++){
        if(i>cnt_bit){
            cout<<0<<' ';
            continue;
        }

        ll cnt=((n-cnt_bit*3%mod)%mod+cnt_bit)%mod;
        // cout<<
        ll mi=(n-cnt_bit*3%mod)%mod;
        cout<<((C(i,(int)cnt)%mod)*(qpow(26,(int)mi)%mod))%mod<<' ';
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
