#include <bits/stdc++.h>
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
const int maxn = 11;

ll a[maxn], b[maxn];
ll p, h, m, n;
set<pair<int, int>> se;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> n >> p >> h >> m;
    while(m--){
        int x, y; cin >> x >> y;
        if(x > y) swap(x, y);
        if(se.count({x, y}) != 0) continue;
        se.insert({x, y});
        b[x + 1] -= 1, b[y] += 1;
    }

    for(int i = 1; i <= n; i++){
        a[i] = a[i - 1] + b[i];
    }

    int temp = a[p];
    for(int i = 1; i <= n; i++){
        cout << a[i] + h << "\n";
    }

    return 0;
}
