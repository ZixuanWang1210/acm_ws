#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#define int long long
using namespace std;

ll n,m;
const ll P=1000000007;

ll qmi(ll a, ll b, ll p){
    ll res = 1 % p;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * (ll)a % p;
        b >>= 1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;

    ll M=m;
    int cnt = 0;
    while(m){
        int num = m & 1;
        if(num == 1) cnt ++;
        m >>= 1;
    }
    // cout<<cnt;
    cout<<qmi(n,cnt,P);
    // cout << 1000000007%P;
    return 0;
}
