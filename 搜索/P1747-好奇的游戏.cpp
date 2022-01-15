#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
// #define pii pair<int, int>
using namespace std;

int dx[12]={1,1,2,2,2,2,-1,-1,-2,-2,-2,-2}, dy[12]={-2,2,-2,-1,1,2,-2,2,-1,1,-2,2};

struct p{
    int x, y;
    int step;
};


int bfs(int x, int y){
    bool vis[100][100] = {false};
    int x1, y1, x2, y2;
    // cin >> x1 >> y1;
    x1 = x, y1 = y;
    x2 = 1, y2 = 1;
    int m_shang = max(x1, x2);
    int m_xia = min(x1, x2);
    int n_shang = max(y1, y2);
    int n_xia = min(y1, y2);
    queue<p> q;
    p tmp;
    tmp.x = x1, tmp.y = y1, tmp.step = 0;
    q.push(tmp);
    vis[x1][y1] = true;
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, stp = q.front().step;
        q.pop();
        if(x == x2 && y == y2){
            cout << stp;
            return 0;
        }
        for(int i = 0; i < 12; i++){
            int xx = x + dx[i], yy = y + dy[i];
            // if(xx < m_xia - 10 || xx > m_shang + 10 || yy > n_shang + 10|| yy < n_xia - 10 || vis[xx][yy] == true) continue;
            if(vis[xx][yy] == true || xx < 1 || yy < 1) continue;
            q.push({xx, yy, stp + 1});
            vis[xx][yy] = true;
        }
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bfs(x1, y1);
    cout << endl;
    bfs(x2, y2);

    return 0;
}
