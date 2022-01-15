#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

ll n;
const int maxn = 1e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll ans = 1;

    for(int i = 1; i <= min(n, ans); i++){
        ans = max(ans, i + a[i]);
        if(ans >= n)    break;
    }
    
    ans = min(n, ans);
    cout << ans;

    return 0;
}
