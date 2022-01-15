#include <bits/stdc++.h>
//typedef long long ll;
typedef unsigned long long ll;

using namespace std;

ll call(ll b, ll p, ll k){
    ll t;
    if(p == 1) return b%k;
    t = call(b, p/2, k)%k;
    return (t*t*(p%2==1?b%k:1)%k);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    ll b, p, k;

    cin >> b >> p >> k;
    cout << b<<"^"<<p<<" mod "<<k<<"=" <<call(b, p, k);

    return 0;
}
