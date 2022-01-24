#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define eps 1e-9
using namespace std;


void solve(){
    double n, m; cin >> n >> m;
    long long red = 0, green = 0;
    long long ans = 0;
    while(n > eps){
        red = 100 * n;
        green = min(10000, (int)(n * 100 * (m - 0.99999999999999)));
        ans += red / 10 + green / 10;
        n = red / 200;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    

    return 0;
}
