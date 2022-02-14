#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define int long long
int n;
const int maxn = 30100000;
int a[maxn], idx;
bool st[maxn];
const int P=1000000007;

void get(int n){
    memset(st, 1, sizeof st);
    for(int i = 2; i <= n; i++){
        if(st[i]){
            a[idx ++] = i;
        }
        for(int j = 0; a[j] <= n / i && j <= idx; j++){
            st[a[j] * i] = false;
            if(i % a[j] == 0) break;
        }
    }
}

ll quick_pow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%P;
        b>>=1;
        a=(a*a)%P;
    }
    return ans;
}


ll inv(ll a,ll b){
    return (a*quick_pow(b,P-2))%P;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    get(30000);
    int l,r; cin>>l>>r;

    ll ans=1;
    bool bz=false;
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(st[i]==false){
            // cout<<i<<endl;
            bz=true;
            ll a=ans%P,b=i;
            ll temp=(a%P*b%P)%P;
            ll tgcd=__gcd(b,a);
            // ans=inv(temp,tgcd);
            ans=temp/tgcd;
            ans%=P;
        }
        else cnt++;
    }
    if(bz==false) cout<<-1;
    else cout<<ans;
    // cout<<endl<<cnt<<endl;
    return 0;
}