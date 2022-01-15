#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy;
int vis[410][410];
int dx[]={1,1,2,2,-1,-1,-2,-2}, dy[]={2,-2,1,-1,2,-2,1,-1};
struct node{
    int x, y;
    int step;
};

void bfs(){
    queue<node>q;
    node start;
    start.x = sx, start.y = sy, start.step = 0;
    q.push(start); 
    vis[sx][sy] = 0; 
    while(!q.empty()){
        node top = q.front(), newP; q.pop();
        for(int i = 0; i < 8; i++){
            int xx = dx[i] + top.x, yy = dy[i] + top.y;
            if(xx>0&&xx<=n&&yy>0&&yy<=m){
                if(vis[xx][yy]==-1){
                    vis[xx][yy] = top.step + 1;
                    newP.step = vis[xx][yy];
                    newP.x = xx, newP.y = yy;
                    q.push(newP);
                }
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

    memset(vis, -1, sizeof(vis));
    cin >>n>>m>>sx>>sy;
    bfs();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            printf("%-5d",vis[i][j]);
        }
        cout << endl;
    }

    return 0;
}
