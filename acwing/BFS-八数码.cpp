#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

queue<pii> q;
int mp[5][5], ans;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int bfs(int sx, int sy){
    q.push({sx, sy});
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && xx <= 3 && yy >=0 && yy <= 3){

            }
        }
    }
}

bool check(){
    int tmp;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 2 && j == 2) continue;
            if(mp[i][j] != ++tmp) return false;
        }
    }
    return true;
}

int dfs(int sx,int sy){
    if(check()){
        if(ans > 100) return -1;
        else return ans;
    }
    for(int i = 0; i < 4; i++){
        int xx = sx + dx[i], yy = sy + dy[i];
        if(xx >= 0 && xx <= 3 && yy >=0 && yy <= 3){
            swap(mp[xx][yy], mp[sx][sy]);
            ans ++;
            dfs(xx, yy);
            ans --;
            swap(mp[xx][yy], mp[sx][sy]);
        }
    }
}

int main(){
    int sx, sy;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            cin >> mp[i][j];
            if(mp[i][j]) sx = i, sy = j;
        }
            
    
    cout << dfs(sx, sy);

    return 0;
}