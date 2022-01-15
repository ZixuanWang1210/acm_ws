#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, step;
int ans[410][410];
int dx[]={1,1,2,2,-1,-1,-2,-2}, dy[]={2,-2,1,-1,2,-2,1,-1};

void dfs(int x, int y, int step){
    ans[x][y] = step;
    if(step>400) return;
    for(int i = 0; i < 8; i++){
        int xx = dx[i] + x, yy = dy[i] + y;
        if(xx>0&&xx<=n&&yy>0&&yy<=m){
            if(ans[xx][yy]==-1||ans[xx][yy] > step+1){
                dfs(xx, yy, step+1);
            }
        }
    }

}

int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    memset(ans,-1,sizeof(ans));
    cin >>n>>m>>x>>y;
    dfs(x, y, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            printf("%-5d",ans[i][j]);
        }
        cout << endl;
    }

    return 0;
}
