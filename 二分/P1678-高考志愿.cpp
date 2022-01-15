#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
// const int maxn = 5;

int m, n;
long long ans;
long long a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    cin >> m >> n;
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);

    for(int i = 0; i < n; i++){
        int st; cin >> st;
        int idx = lower_bound(a, a + m, st) - a;
        
        if(idx == m) ans += st - a[m - 1];
        else
            if(idx == 0) ans += a[0] - st;
            else ans += min(abs(a[idx] - st), abs(st - a[idx - 1]));
    }

    cout << ans;
    return 0;
}