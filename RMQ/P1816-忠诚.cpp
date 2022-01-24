#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e5 + 10;
int n, m;
int dp[maxn][20];
int a[maxn];

void init(){
    for(int j = 0; j <= 20; j ++){
        for(int i = 1;i+(1<<j)-1<=m;i++){
            if(j == 0) {dp[i][j] = a[i];}
            else dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int ask(int l, int r){
    int len = r - l + 1, k = log2(len);
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    

    cin >> m >> n;
    
    for(int i = 1; i <= m; i ++) cin >> a[i];

    init();

    while(n--){
        int l, r; cin >> l >> r;
        cout << ask(l, r) << " ";
    }

    return 0;
}
