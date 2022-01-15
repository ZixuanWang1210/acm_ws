#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e5 + 10;
int n, m;
int row[maxn], col[maxn], s[maxn], c[maxn];

ll work(int a[], int n){
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }

    if(s[n] % n) return -1;

    int avg = s[n] / n;

    c[1] = 0;
    for(int i = 2; i <= n; i++){
        c[i] = s[i - 1] - (i - 1) * avg;
    }

    sort(c + 1, c + n + 1);
    ll res = 0;
    for(int i = 1; i <= n; i++) res += abs(c[i] - c[(n + 1) / 2]);

    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    int t; cin >> n >> m >> t;
    
    while(t--){
        int x, y; cin >> x >> y;
        row[x] ++, col[y] ++;
    }

    ll r = work(row, n);
    ll c = work(col, m);

    if(r != -1 && c != -1) cout << "both " << r + c;
    else if(r != -1) cout << "row " << r;
    else if(c != -1) cout << "column " << c;
    else cout << "impossible";

    return 0;
}
