#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1100;
char mp[maxn][maxn];
int n, m;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0,- 1, 1, -1, 1, -1, 0};

void sol(){
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> mp[i][j];

    for(int x = 1; x <= n; x ++){
        for(int y = 1; y <= m; y ++){
            if(mp[x][y] == 'P'){
                ans ++;
                for(int k = 0; k < 8; k ++){
                    int xx = x + dx[k], yy = y + dy[k];
                    if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
                    if(mp[xx][yy] == '*'){
                        ans --;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        sol();
    }
    

    return 0;
}
