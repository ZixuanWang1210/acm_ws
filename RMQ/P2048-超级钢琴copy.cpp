#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 5e5 + 10;
ll dp[maxn][24], s[maxn];
int n;

void ST(){
    for(int j = 0; j <= 24; j ++){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++){
            if(j == 0) dp[i][j] = i;
            else dp[i][j] = max(dp[i][j-1], dp[i+(1<<j-1)][j-1]);
        }
    }
}

int query(int l, int r){
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r-(1<<k)+1][k]);
}

struct node{
    int x,l,r,m;
    node(int o, int l, int r) : x(x), l(l), r(r), m(query(l, r)) {}
    friend bool operator<(const node&a, const node& b){
        return s[a.m] - s[a.x-1] < s[b.m] - s[b.x-1];
    }
};

priority_queue<node> q;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, L, R;
    cin >> n >> k >> L >> R;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        s[i] += s[i-1];
    }

    ST();
    for(int i = 1; i <= n; i ++){
        if(i + L - 1 <= n)
            q.push(node(i, i + L - 1, min(i + R - 1, n)));
    }
    
    ll ans = 0;
    while(k--){
        node t = q.top(); q.pop();
        int x = t.x, l = t.l, r = t.r, m = t.m;

        ans += s[m] - s[x-1];
        if(l != m) q.push(node(x, l, m-1));
        if(m != r) q.push(node(x, m + 1, r));
    }

    cout << ans;

    return 0;
}
