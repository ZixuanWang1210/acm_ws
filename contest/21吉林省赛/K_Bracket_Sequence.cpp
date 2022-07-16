#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
const int N=100010;

ll fac[N],infac[N];
ll qpow(ll a, ll b)
{
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ans = ans * a % mod;
    return ans;
}
void init()
{
    fac[0]=infac[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        infac[i]=infac[i - 1] * qpow(i,mod-2)%mod;
    }
}
ll C(ll n, ll m)	
{
    if (n < m)
        return 0;
    return fac[n] * infac[m] % mod * infac[n - m] % mod;
}