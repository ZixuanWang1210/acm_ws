#include <bits/stdc++.h>
typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 1e5 + 10;
using namespace std;

ll n, ans1, ans2;
ll a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    ll sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        if(i < 2) continue;
        if(b[i] > 0) sum1 += b[i];
        else sum2 -= b[i];
    }
    
    ans1 = max(sum1, sum2);
    ans2 = abs(sum1 - sum2) + 1;

    cout << ans1 << "\n" << ans2;

    return 0;
}
