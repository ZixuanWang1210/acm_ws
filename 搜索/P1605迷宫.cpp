#include <bits/stdc++.h>
using namespace std;

int g_x, g_y, n, t, m, num = 0, s_x, s_y, z_x, z_y;
int mp[10][10] {}, vis[10][10] {};
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int debug(){
    cout <<"-----------------"<< endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << vis[i][j] <<" ";

        }
        cout << endl<<endl;
    }
}

void dfs(int n_x, int n_y){
    if(n_x==g_x && n_y==g_y){
        num++; return;
    }
    for(int i = 0; i < 4; i++){
        int x = n_x + dx[i], y = n_y + dy[i];
        if(x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]!=1&&vis[x][y]!=1){
            vis[x][y] = 1;
            dfs(x, y);
            vis[x][y] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin>>n>>m>>t;
    cin>>s_x>>s_y>>g_x>>g_y;
    for(int i = 0; i < t; i++){
        cin>>z_x>>z_y;
        mp[z_x][z_y] = 1;
    }
    vis[s_x][s_y] = 1;
    dfs(s_x, s_y);
    //cout <<"aaaaaa";
    cout << num;

    return 0;
}
