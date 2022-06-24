#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353
#define LL long long
#define int long long

using namespace std;
const int maxn=3e5+10;
int a[maxn],inv[maxn],ki[maxn],k;
int n;

namespace NTT
{
const long long g = 3;
const long long p = 998244353;
long long wn[35];
long long pow2(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void getwn()
{
    for (int i = 0; i < 25; i++) wn[i] = pow2(g, (p - 1) / (1LL << i));
}
void ntt(long long *a, int len, int f)
{
    long long i, j = 0, t, k, w, id;
    for (i = 1; i < len - 1; i++)
    {
        for (t = len; j ^= t >>= 1, ~j & t;);
        if (i < j) swap(a[i], a[j]);
    }
    for (i = 1, id = 1; i < len; i <<= 1, id++)
    {
        t = i << 1;
        for (j = 0; j < len; j += t)
        {
            for (k = 0, w = 1; k < i; k++, w = w * wn[id] % p)
            {
                long long x = a[j + k], y = w * a[j + k + i] % p;
                a[j + k] = (x + y) % p;
                a[j + k + i] = (x - y + p) % p;
            }
        }
    }
    if (f)
    {
        for (i = 1, j = len - 1; i < j; i++, j--) swap(a[i], a[j]);
        long long inv = pow2(len, p - 2);
        for (i = 0; i < len; i++) a[i] = a[i] * inv % p;
    }
}
void mul(long long *a, long long *b, int l1, int l2)
{
    int len, i;
    for (len = 1; len <= l1 + l2; len <<= 1);
    for (i = l1 + 1; i <= len; i++) a[i] = 0;
    for (i = l2 + 1; i <= len; i++) b[i] = 0;
    ntt(a, len, 0); ntt(b, len, 0);
    for (i = 0; i < len; i++) a[i] = a[i] * b[i] % p;
    ntt(a, len, 1);
}
};

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

void init(int n){
    inv[0]=inv[1]=1;
    for(int i=2;i<=10;i++){
        inv[i]=inv[i-1]*qmi(i,mod-2,mod)%mod;
        cout<<inv[i]<<' ';
    }
}

void get_ki(int k,int len){
    k=(k%mod+mod)%mod;
    ki[0]=1;
    for(int i=1;i<len;i++){
        ki[i]=ki[i-1]*inv[i]%mod*((k+i-1)%mod)%mod;
        // cout<<ki[i]<<" ";
    }
}

void sol(){
    NTT::getwn();
    init(100000);
    cin>>n>>k;
    get_ki(k,n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    NTT::mul(a,ki,n,n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
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
