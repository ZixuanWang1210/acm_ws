#include <bits/stdc++.h>
using namespace std;

int r, c, ans;
int mp[200][200];
int d[200][200];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};


bool isTure(int x, int y){
    return (x<r&&x>=0&&y<c&&y>=0) ? true : false;
}

int dfs(int x, int y){
    int step;
    if(d[x][y]) return d[x][y];
    d[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(isTure(xx, yy)&&mp[x][y]>mp[xx][yy]){
            d[x][y] = max(d[x][y], dfs(xx, yy)+1);            
        }
    }
    //d[x][y]  = step;
    return d[x][y];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> r>>c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mp[i][j];
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ans = max(ans, dfs(j, j));
        }
    }
    //dfs(0, 0, 0);
    cout << ans;
    return 0;
}
