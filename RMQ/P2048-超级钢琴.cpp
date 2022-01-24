#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 5e5 + 10;
int a[maxn];
ll tr[maxn];
int n, k, l, r;
priority_queue<ll> q;

// void init(){
//     for(int j = 1; j <= 23; j ++){
//         for(int i = 1; i + (1 << j) - 1 <= n; i ++){
//             dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
//             debug(dp[i][j]);
//         }
//     }
// }

// ll ask(int l, int r){
//     int k = log2(l - r + 1);
//     return max(dp[l][k], dp[r - (1 << k) + 1][k]);
// }
int lowbit(int x){
    return x & -x;
}

void add(int x, int k){
    for(; x <= n; x += lowbit(x)) tr[x] += k;
}

ll ask(int x){
    ll ans = 0;
    for(; x; x -= lowbit(x)) ans += tr[x];
    return ans;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k >> l >> r;
    for(int i = 1; i <= n; i ++){
        int t; cin >> t;
        add(i, t);
    }
    // init();

    // cout << ask(1) << ' '<< ask(4);

    for(int i = 1; i <= n; i ++){
        for(int len = l - 1; len <= r - 1; len ++){
            if(i + len > n) break; 
            // cout << i << " " << i + len << " ";
            ll temp = ask(i + len) - ask(i - 1);
            // debug(temp);
            q.push(temp);
        }
    }

    ll ans = 0, re = 0;
    for(int i = 1; i <= k; i ++){
        ll top = q.top();
        // cout << top << endl;
        // if(top > 0) ans += top;
        // else{
        //     ans += re;
        //     q.pop();
        //     continue;
        // }
        // re = top;
        // q.pop();
        ans += top;
        q.pop();
    }
    cout << ans;
    return 0;
}
