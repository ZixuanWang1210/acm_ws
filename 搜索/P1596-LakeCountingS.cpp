#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
typedef pair<int, int> pii;

char a[maxn][maxn];
int n, m, ans;
int dx[] = {0,-1,-1,-1,0,0,1,1,1}, dy[] = {0,-1,0,1,-1,1,-1,0,1};

int judge(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < m && a[x][y] == 'W') return true;
    else return false;
}

pair<int, int> check(){
    pair<int, int> p;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'W'){
                p = {i, j};
                return p;
            }
        }
    return {0x3f3f3f, 0x3f3f3f};
}

void bfs(int sx, int sy){
    queue<pii> q;
    q.push({sx, sy});
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 9; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(judge(xx, yy)){
                q.push({xx, yy});
                a[xx][yy] = 'X';
            }
        }
    }
}

void debug(){
    cout << "----------------------"<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
        
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    while(1){
        int x = check().first, y = check().second;
        if(x == 0x3f3f3f) break;
        ans ++;
        bfs(x, y);
        // debug();
    }

    cout << ans;
    return 0;
}