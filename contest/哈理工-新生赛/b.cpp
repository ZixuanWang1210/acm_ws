#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

ll a, n, p;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> a;
    // if(n * 5 >= a){
    //     cout << 0;
    //     return 0;
    // }
    // else{
    //     cout << 
    // }
    ll ans1 = a / 5;
    if(ans1 > n) ans1 = n;

    ll res = a - ans1 * 5;
    ll ans2 = res;
    cout << ans1 << " " << ans2;
    

    return 0;
}
