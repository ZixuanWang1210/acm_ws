#include <bits/stdc++.h>
using namespace std;

int ans, n, k;
// int dfs(int k, int res, int last){
//     if(k==0&&res==0) {ans++; return 0;}
//     if(k==0&&res!=0) return 0;
//     for(int i = last; i <= res/2; i++){
//         res -= i;
//         dfs(k-1, res, i);
//     }
// }
int dfs1(int pre, int sum, int cnt){
    if(cnt == k){
        if(sum == n) ans++;
        return 0;
    }
    for(int i = pre; i <= n; i++){
        if(sum + i * (k - cnt) > n) break;
        dfs1(i, sum+i, cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n >> k;
    // dfs(k, n, 1);
    for(int i = 1; i <= n/k; i++){
        dfs1(i, i, 1);
    }
    cout << ans;
    

    return 0;
}
