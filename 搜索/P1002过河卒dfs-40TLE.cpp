#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int bx, by, cx, cy, ans;
int dx[]={1,0}, dy[]={0,1};
int mx[]={1,1,2,2,-1,-1,-2,-2}, my[]={2,-2,1,-1,2,-2,1,-1};
bool vis[30][30];

void debug(){
    cout <<" =========="<< endl;
    for(int i = 0; i <= bx; i++){
        for(int j = 0; j <= by; j++){
            cout << vis[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "==============="<<endl;
}

bool isTrue(int x, int y){
    return (x>=0&&x<=bx&&y>=0&&y<=by&&vis[x][y]==false) ? true : false;
} 

void dfs(int x, int y){
    //debug();
    if(x==bx&&y==by){
        ans++;
        return;
    }

    for(int i = 0; i < 2; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(isTrue(xx, yy)){
            vis[xx][yy] = true;
            dfs(xx, yy);
            vis[xx][yy] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> bx >> by >> cx >> cy;
    vis[cx][cy] = true;
    for(int i = 0; i < 8; i++){
        int xx = cx + mx[i], yy = cy + my[i];
        //cout << xx <<" "<< yy <<" " << my[i]<< endl;
        if(isTrue(xx, yy)) vis[xx][yy] = true;
        //debug();
    }
    vis[0][0] = 1;
    dfs(0, 0);
    cout << ans;   

    return 0;
}
