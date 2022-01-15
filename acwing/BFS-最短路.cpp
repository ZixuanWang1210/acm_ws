#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 10;

int n, m;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}; 
int mp[maxn][maxn];
int st[maxn][maxn];
pii Prv[maxn][maxn];
queue<pii> q;

bool pass(int x, int y){
    return (mp[x][y]) ? false : true;
}

void bfs(){
    q.push({1, 1});
    st[1][1] = 0;
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int x = q.front().first, y = q.front().second;
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] != 1 && st[xx][yy] == -1){
                st[xx][yy] = st[x][y] + 1;
                Prv[xx][yy] = {x, y}; //记录路径
                q.push({xx, yy});
            }
        }
        q.pop();
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mp[i][j];
    
    memset(st, -1, sizeof st);
    
    bfs();

    cout << st[n][m] << endl;

    int x = n, y = m;
    while(x != 1 || y != 1){
        cout << x << " " << y << endl;
        pii t = Prv[x][y];
        x = t.first, y = t.second;
    }
    cout << "1 1";
    return 0;
}