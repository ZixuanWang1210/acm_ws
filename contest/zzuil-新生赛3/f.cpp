#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// #define int ll
// typedef unsigned long long ull;

using namespace std;
const int maxn = 1e5 + 10;
ll a[maxn], x[maxn], d[maxn], m[maxn];

int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> n;
    ll _min = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> d[i] >> m[i];
        for(int i = 0; i < 60; i++){
            ll temp = (360 + 60 - i) * (x[i] + (i/d[i]) * m[i]);
            _min = min(_min, temp);
        }
    }

    cout << _min;
    return 0;
}
