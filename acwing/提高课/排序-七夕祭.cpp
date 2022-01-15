#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// const int maxn = 1e5 + 10;
const int maxn = 5;
using namespace std;

int n, m;
ll c[maxn], r[maxn], sc[maxn], sr[maxn], a1[maxn], a2[maxn];
bool flag1 = true, flag2 = true;
ll res1, res2;
ll avg1, avg2;
int t;

void solve(){
    for(int i = 1; i <= m; i++){
        sc[i] = sc[i - 1] + c[i];
        avg2 += c[i];
    }
    if(avg2 % m != 0) flag2 = false;
    avg2 /= m;

    for(int i = 1; i <= n; i++){
        sr[i] = sr[i - 1] + r[i];
        avg1 += r[i];
    }
    if(avg1 % n != 0) flag1 = false;
    avg1 /= n;

    for(int i = 1; i <= m; i++){
        a2[i] = i * avg2 - sc[i];
    }

    for(int i = 1; i <= n; i++){
        a1[i] = i * avg1 - sr[i];
    }

    nth_element(a1 + 1, a1 + n / 2 + 1, a1 + n + 1);
    nth_element(a2 + 1, a2 + m / 2 + 1, a2 + m + 1);


    for(int i = 1; i <= n; i++){
        res1 += abs(a1[i] - a1[n / 2 + 1]);
    }

    for(int i = 1; i <= m; i++){
        res2 += abs(a2[i] - a2[m / 2 + 1]);
    }


}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> m >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        r[x] ++, c[y] ++;
    }

    solve();

    if(flag1 && flag2) cout << "both " << res1 + res2;
    else if(flag1 && !flag2) cout << "row " << res1;
    else cout << "column " << res2;

    return 0;
}
