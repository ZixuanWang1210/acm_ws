#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int, int>
using namespace std;

const int maxn = 55;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int mp[maxn][maxn];
bool vis[maxn][maxn] = {false};
int n, m;
vector<pii> v1, v2;

void debug(){
    cout << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++ ){
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int sx, int sy, vector<pii> &v){
    queue<pii> q;
    q.push({sx, sy});
    v.push_back({sx, sy});
    vis[sx][sy] = true;
    // mp[sx][sy] = 0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        for(int i = 0; i < 4; i ++ ){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] == false && mp[xx][yy] == 1){
                v.push_back({xx, yy});
                // debug();
                q.push({xx, yy});
                vis[xx][yy] = true;
                // mp[xx][yy] = 0;
            }
        }
        q.pop();
    }
    return;
}

int get(int sx, int sy, int dx, int dy){
    return (abs(sx - dx) + abs(sy - dy) - 1);
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            char temp; cin >> temp;
            if(temp == '.') mp[i][j] = 0;
            else mp[i][j] = 1;
        }
    }
    bool flag = true;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(mp[i][j] == 1 && vis[i][j] == false){
                if(flag == true){
                    bfs(i, j, v1);
                    flag = false;
                }
                else bfs(i, j, v2);
            }

        }
    }
    
    int _min = 0x3f3f3f3f;
    for(auto x : v1){
        for(auto y : v2){
            _min = min(get(x.first, x.second, y.first, y.second), _min);
        }
    }
    cout << _min;

    return 0;
}
