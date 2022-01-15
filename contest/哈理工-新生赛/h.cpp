#include <bits/stdc++.h>
#define endl "\n"
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
const int maxn = 1e6 + 10;

int n, l;
int a1, an;
int a[maxn];

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> l >> n;
    int _min = -1, _max = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        int x = a[i];
        if(i == 0) a1 = x;
        if(i == n - 1) an = x;
        _min = max(_min, min(x, l - x));
    }
    _max = max(l - a1, an);
    
    cout << _min << " " << _max;
    return 0;
}
