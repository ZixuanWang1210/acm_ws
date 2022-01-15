#include <bits/stdc++.h>
using namespace std;

int mp[100][100] {};
int a[100], b[100], c[100], d[100];//hang lie duijiaoxian
int num = 0, n;

int dfs(int y){
    if(y == n+1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mp[i][j] == 1 && num < 3) cout << j <<" ";
            }           
        }
        num++;
        if(num <= 3) cout << endl;
        return 0; 
    };
    for(int i = 1; i <= n; i++){
        if(b[i]==1||c[i+y]==1||d[i-y+n]==1) continue;
        b[i] = 1, c[i+y] = 1, d[i-y+n] = 1, mp[y][i] = 1;
        dfs(y+1);
        b[i] = 0, c[i+y] = 0, d[i-y+n] = 0, mp[y][i] = 0;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;

    dfs(1);
    cout << num;
    return 0;
}
