#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int, int>
using namespace std;

const int maxn = 1010;
int n, m, ans;
char mp[maxn][maxn];
queue<pii> q;
int dx[] = {-1, 0}, dy[] = {0, 1};

bool judge(int x, int y){
    if(x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#') return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    
    q.push({n, 1});

    while(!q.empty()){
        auto top = q.front();
        if(top.first == 1 && top.second == m) ans ++;
        q.pop();
        for(int i = 0; i < 2; i++){
            int xx = top.first + dx[i], yy = top.second + dy[i];
            if(judge(xx, yy) == true){
                // cout << xx << " " << yy << endl;
                q.push({xx, yy});
            }
        }
        
    }

    cout << ans;

    return 0;
}
