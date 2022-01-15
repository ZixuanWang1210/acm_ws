#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

int n, ans;
const int maxn = 1e5 + 10;
int a[maxn];

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    for(int i = 0; i < n - 1; i++){
        ans += a[i] * (n - i - 1);
    }

    cout << ans;

    return 0;
}
