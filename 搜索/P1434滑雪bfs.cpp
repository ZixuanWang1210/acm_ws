#include <bits/stdc++.h>
using namespace std;

int r, c, ans;
int mp[200][200];
int vis[200][200];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
struct node{
    int x, y;
};

bool isTure(int x, int y){
    return (mp[x][y]!=0&&x<r&&x>=0&&y<c&&y>=0) ? true : false;
}


void bfs(int x, int y){
    queue<node> q;
    //queue<int> step;
    node start, next;
    int now(0), cnt_layer(0);
    start.x = x, start.y = y;
    vis[x][y] = 1;
    q.push(start);
    //step.push(0);
    while(!q.empty()){
        if(now==0){
            ++cnt_layer;
            now = q.size();
        }
        for(int i = 0; i < 4; i++){
            int xx = q.front().x + dx[i], yy = q.front().y + dy[i];
            if(isTure(xx, yy)&&(mp[q.front().x][q.front().y]>mp[xx][yy])){
                next.x = xx, next. y = yy;
                vis[xx][yy] = 1;
                //step.push(step.front()+1);
                q.push(next);
            }
        }
        q.pop();
        --now;
        //step.pop();
    }
    ans = ans < cnt_layer ? cnt_layer : ans;
    //return step.front();
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
            if(isTure(i-1, j)&&mp[i-1][j]>mp[i][j]) continue;
            if(isTure(i, j-1)&&mp[i][j-1]>mp[i][j]) continue;
            if(isTure(i+1, j)&&mp[i+1][j]>mp[i][j]) continue;
            if(isTure(i, j+1)&&mp[i][j+1]>mp[i][j]) continue;
            bfs(i, j);
        }
    }
    cout << ans;
    return 0;
}
