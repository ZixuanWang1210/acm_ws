#include <bits/stdc++.h>

using namespace std;

const int N = 510;

typedef long long ll;

struct node{
    int x,y;
    ll w;
    bool operator < (const node &x) const{
        return w > x.w;
    }
};
int rou[4][2]={-1,0,0,1,1,0,0,-1};
bool st[N][N];
ll g[N][N];
int T,n,m;

int main(){
    cin>>T>>n>>m;

    while(T--){
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
          cin>>g[i][j];
          if(g[i][j]==0) g[i][j]=1e18;
          else if(g[i][j]==-1) g[i][j]=0;  
          st[i][j]=false;
        }        

        priority_queue<node>q;
        for(int j=2;j<=m;j++) if(g[1][j]!=1e18) q.push({1,j,g[1][j]}) ;
        for(int i=2;i<n;i++) if(g[i][m]!=1e18) q.push({i,m,g[i][m]}) ;

        ll res=1e18;
        while(q.size()){
            auto p=q.top();
            q.pop();
            int x=p.x,y=p.y;
            ll w=p.w;        
            if(y==1||x==n) {
                 res=min(res,w);
                 continue;   
             }

            if(st[x][y]) continue;

            st[x][y]=true;
            for(int i=0;i<4;i++){
                int xi=x+rou[i][0];
                int yi=y+rou[i][1];
                if(xi<1||xi>n||yi<1||yi>m||g[xi][yi]==1e18) continue;
                q.push({xi,yi,w+g[xi][yi]});
            }
        }

        if(res==1e18) puts("-1");
        else cout<<res<<endl;
    }

    return 0;
}