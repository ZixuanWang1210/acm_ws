#include <bits/stdc++.h>
using namespace std;

int n, a[40][40], ans[40][40];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
struct point{
    int x, y;
    int data;
    point(){
        x = 0, y = 0, data = -1;
    }
};

int debug(){
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= n+1; j++){
            //if(a[i][j]==0) ans[i][j] = 2;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout<< endl;
}

void bfs(int x, int y){
    queue<point>q;
    point p;
    p.x = x, p.y = y, p.data = a[x][y];
    a[x][y] = 1;
    q.push(p);
    while(!q.empty()){
        //debug();
        point newP;
        int xx = q.front().x, yy = q.front().y, da = q.front().data;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = xx + dx[i], ny = yy + dy[i];
            if(nx>=0&&nx<=n+1&&ny>=0&&ny<=n+1&a[nx][ny]==0){
                newP.x = nx, newP.y = ny, newP.data = 1;
                a[nx][ny] = 1;
                q.push(newP);
            }
        }

    }
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            ans[i][j] = a[i][j];
        }
    }
    
    //cout << endl;
    bfs(0, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j]==0) ans[i][j] = 2;
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
