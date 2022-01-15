#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;

int n;
int s[20], b[20];
int ans = 0x3f3f3f3f;
bool st[20] = {false};

int dfs(int num, int now_s, int now_k, int x){
    if(x == n){
        ans = min(ans, abs(now_s - now_k));
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(st[i]) continue;
        dfs(num, now_s * s[i], now_k + b[i], x + 1);
    }
    return 0;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i] >> b[i];
    
    for(int i = 1; i <= n; i++)
        dfs(i, 1, 0, 0);

    cout << ans;
    


    return 0;
}