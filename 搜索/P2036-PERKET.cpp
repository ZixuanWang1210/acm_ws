#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;

int n;
int s[20], b[20];
int ans = 0x7fffffff;
bool st[20] = {false};

// int dfs(int num, int now_s, int now_k, int x){
//     if(x == n){
//         ans = min(ans, abs(now_s - now_k));
//         return 0;
//     }
//     for(int i = 0; i < n; i++){
//         if(st[i]) continue;
//         dfs(num, now_s * s[i], now_k + b[i], x + 1);
//     }
//     return 0;
// }

void dfs(int i, int _s, int k){
    if(i > n){
        if(_s == 1 && k == 0) return;
        else {ans = min(ans, abs(_s - k)); return;}
    }
    dfs(i + 1, _s, k);
    dfs(i + 1, _s * s[i], k + b[i]);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i] >> b[i];
    
    // for(int i = 1; i <= n; i++){
    //     memset(st, false, sizeof st);
    //     dfs(i, 1, 0, 0);
    // }
    
    dfs(1, 1, 0);

    cout << ans;
    


    return 0;
}