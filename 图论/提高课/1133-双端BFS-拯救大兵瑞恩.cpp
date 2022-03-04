#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=150,M=3600;
int g[N][N];
int h[N],ne[M],e[M],idx,w[M];
int n,m,p,k;
int dis[M][M],key[M];
bool st[M][M];
set<pii> edge;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void build(){
    int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int u=0;u<4;u++){
                int x=i+dx[u],y=j+dy[u];
                if(!x||x>n||!y||y>m) continue;
                int a=g[i][j],b=g[x][y];
                // cout<<a<<' '<<b<<endl;
                if(!edge.count({a,b})) add(a,b,0);
            }
        }
    }
}

int bfs(){
    memset(dis,0x3f,sizeof dis);
    dis[1][0]=0;

    deque<pii> q;
    q.push_back({1,0});

    while(q.size()){
        pii t=q.front(); q.pop_front();
        // cout<<t.first<<endl;

        if(st[t.first][t.second]) continue;
        st[t.first][t.second]=1;

        if(t.first==m*n) return dis[t.first][t.second];

        if(key[t.first]){
            int state=t.second|key[t.first];
            if(dis[t.first][state]>dis[t.first][t.second]){
                dis[t.first][state]=dis[t.first][t.second];
                q.push_front({t.first,state});
            }
        }

        for(int i=h[t.first];~i;i=ne[i]){
            int j=e[i];
            if(w[i]&&!(t.second>>w[i]-1&1)) continue;
            if(dis[j][t.second]>dis[t.first][t.second]+1){
                dis[j][t.second]=dis[t.first][t.second]+1;
                q.push_back({j,t.second});
            }
        }
    }
    return -1;
}
// int bfs()
// {
//     memset(dis, 0x3f, sizeof dis);
//     dis[1][0] = 0;

//     deque<pii> q;
//     q.push_back({1, 0});

//     while (q.size())
//     {
//         pii t = q.front();
//         q.pop_front();
//         // cout<<t.first<<endl;

//         if (st[t.first][t.second]) continue;
//         st[t.first][t.second] = true;

//         if (t.first == n * m) return dis[t.first][t.second];

//         if (key[t.first])
//         {
//             int state = t.second | key[t.first];
//             if (dis[t.first][state] > dis[t.first][t.second])
//             {
//                 dis[t.first][state] = dis[t.first][t.second];
//                 q.push_front({t.first, state});
//             }
//         }

//         for (int i = h[t.first]; ~i; i = ne[i])
//         {
//             int j = e[i];
//             if (w[i] && !(t.second >> w[i] - 1 & 1)) continue;   // 有门并且没有钥匙
//             if (dis[j][t.second] > dis[t.first][t.second] + 1)
//             {
//                 dis[j][t.second] = dis[t.first][t.second] + 1;
//                 q.push_back({j, t.second});
//             }
//         }
//     }

//     return -1;
// }

int main(){
    cin>>n>>m>>p>>k;

    for(int i=1,idx=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g[i][j]=idx++;
            // cout<<g[i][j]<<' ';
        }
        // cout<<endl;
    }

    memset(h,-1,sizeof h);
    for(int i=1;i<=k;i++){
        int x,y,xx,yy,gg; cin>>x>>y>>xx>>yy>>gg;
        int a=g[x][y],b=g[xx][yy];
        edge.insert({a,b}), edge.insert({b,a});
        if(gg) add(g[x][y],g[xx][yy],gg),add(g[xx][yy],g[x][y],gg);
    }

    int s; cin>>s;
    for(int i=1;i<=s;i++){
        int x,y,c; cin>>x>>y>>c;
        key[g[x][y]]|=1<<c-1;
    }

    build();
    cout<<bfs()<<endl;

    return 0;
}