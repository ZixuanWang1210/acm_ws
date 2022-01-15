#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

int m, x, y, t;
int mp[302][302];
bool vis[302][302];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
struct node{
    int x, y, step;
};

int bfs(){
    queue<node> q;
    node start;
    start.x = 0, start.y = 0, start.step = 0;
    vis[0][0] = true;
    q.push(start);
    // while(!q.empty()) {
	// 	node b=q.front();
	// 	q.pop();
	// 	for(int d=0; d<4; ++d) {
	// 		node c;
	// 		c.x=b.x+dx[d],c.y=b.y+dy[d],c.step=b.step+1;
	// 		if(c.x==-1||c.y==-1)continue;//判边界
	// 		if(mp[c.x][c.y]==INF)return c.step;//永远不会有流星
	// 		if(c.step<mp[c.x][c.y]&&!vis[c.x][c.y]) {//在流星到达之前并且没走过
	// 			q.push(c);
	// 			vis[c.x][c.y]=1;//标记为走过
	// 		}
	// 	}
	// }
    while(!q.empty()){
        
        int xx, yy, ss;
        for(int i = 0; i < 4; i++){
            node next;
            xx = q.front().x + dx[i], yy = q.front().y + dy[i], ss = q.front().step + 1;
            if(xx==-1||yy==-1) continue;
            if(mp[xx][yy]==inf) return ss;
            if(ss<mp[xx][yy] && !vis[xx][yy]){
                next.x = xx, next.y = yy, next.step = ss;
                q.push(next);
                vis[xx][yy] = true;
            }
        }
        q.pop();
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> m;
    memset(mp,0x3f,sizeof(mp));
    for(int i = 0; i < m; i++){
        cin >> x >> y >> t;
        mp[x][y] = min(mp[x][y], t);
        for(int j = 0; j < 4; j++){
            if(x+dx[j]==-1||y+dy[j]==-1) continue;
            mp[x+dx[j]][y+dy[j]] = min(mp[x+dx[j]][y+dy[j]], t);
        }
    }

    cout << bfs();
    return 0;
}
