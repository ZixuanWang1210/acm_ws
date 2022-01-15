#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

double t, e, h;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> t >> h >> e;
    // int a = 0.6;
    // cout << a;
    int ans = 0.2 * t + 0.3 * h + 0.5 * e;
    cout << ans << endl;
    

    return 0;
}
