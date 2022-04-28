#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

// int st[10][10];
int dx[10] = {0 , 1 , 1 , 1 , -1 , -1 , -1 , 0 , 0 , 0};
int dy[10] = {0 , -1 , 0 , 1 , 1 , 0 , -1 , 1 , 0 , -1};
int mp[20][20];

bool dfs(int s,int x,int y){
    if(s==0) return 1;
    for(int i=1;i<=9;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>8||xx<=0||yy>8||yy<=0) continue;
        if(mp[xx-8+s-1][yy]||mp[xx+s-8][yy]) continue;
        if(dfs(s-1,xx,yy)) return 1;
    }
    return 0;
}

void sol(){
    int bgx,bgy;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            char tt; cin>>tt;
            if(tt=='S') mp[i][j]=1;
            if(tt=='M') bgx=i,bgy=j;
        }
    }
    if(dfs(8,bgx,bgy)) cout<<"WIN";
    else cout<<"LOSE";
    
    return;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
