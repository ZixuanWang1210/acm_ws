#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    ull a, b, p;
    cin >> a >> b >> p;
    ull res = 0;
    while(a){
        if (a & 1) res = (res + b) % p;
        b = (b + b) % p;
        a >>= 1;
    }

    cout << res;

    return 0;
}
