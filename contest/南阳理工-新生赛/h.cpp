#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>
using namespace std;

const int maxn = 1100;
int mp[maxn][maxn];
int n, cnt, ans;
struct p{
    int x, y, step;
};
queue<p> q;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

void debug(){
    cout << endl << endl << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    cout << cnt << endl;
}

int bfs(){
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, step = q.front().step;
        // cout << step << endl;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > n || mp[xx][yy] == 1) continue;
            q.push({xx, yy, step + 1});
            if(!mp[xx][yy]) cnt ++;
            if(cnt == n * n) return step + 1;
            mp[xx][yy] = 1;
            // debug();
        }
        q.pop();
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j  = 1; j <= n; j++){
            char temp; cin >> temp;
            if(temp == '.') mp[i][j] = 0;
            else{
                mp[i][j] = 1; cnt ++;
                q.push({i, j, 0});
            }
        }
    }

    cout <<  bfs();

    return 0;
}
