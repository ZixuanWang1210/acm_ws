#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int mp[1010][1010];
bool vis[1010][1010];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
typedef struct point{
    int x, y;
};

bool isTrue(int a, int b){
    return (a>=0&&a<n&&b>=0&&b<n&&vis[a][b]==false&&(mp[a][b])?0:1) ? true : false;
}


int bfs(int a, int b){
    queue<point>q;
    queue<int>s;
    point start, temp;
    start.x = a, start.y = b;
    vis[a][b] = true;
    q.push(start); s.push(1);
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int x = q.front().x + dx[i], y = q.front().y + dy[i];
            if(!isTrue(x, y)) continue;
            vis[x][y] = true;
            temp.x = x, temp.y = y;
            q.push(temp);
            s.push(s.front()+1);
        }   
        q.pop();
        s.pop();
    }
    cout << s.front() << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>mp[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        bfs(a, b);
    }

    return 0;
}
