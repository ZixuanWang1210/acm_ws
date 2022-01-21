#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int maxn = 2e6 + 10;
int n, m;
int dp[maxn][21];
int a[maxn];

void init(){
    for(int j = 1; j <= 21; j ++){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++){
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> dp[i][0];

    init();
    cin >> m;
    while(m--){
        int l, r; cin >> l >> r;
        cout << query(l, r) << endl;
    }
    

    return 0;
}
