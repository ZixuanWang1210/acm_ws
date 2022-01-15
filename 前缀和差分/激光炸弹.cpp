#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 5000 + 10;
using namespace std;

int n = maxn, r, ans, N;
int a[maxn][maxn], s[maxn][maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> N >> r;
    r = min(r, 5001);
    for(int i = 0; i < N; i++){
        int x, y, w; cin >> x >> y >> w;
        a[x + 1][y + 1] += w;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    for(int i = r; i <= n; i++){
        for(int j = r; j <= n; j++){
            ans = max(ans, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
        }
    }
    cout << ans;

    return 0;
}
