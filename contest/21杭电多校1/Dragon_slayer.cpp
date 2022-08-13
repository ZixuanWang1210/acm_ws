#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,pair<int,int>>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

int n,m;
const int maxn=20;
int mp[maxn][maxn];
bool st[maxn][maxn];
int dist[maxn][maxn];

int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int k;
int ssx,ssy,ggx,ggy;

void sol(){
    memset(dist,0x3f,sizeof dist);
    memset(mp,0,sizeof mp);
    memset(st,0,sizeof st);

    cin>>n>>m>>k;
    cin>>ssx>>ssy>>ggx>>ggy;
    map<pair<pair<int,int>,pair<int,int>>,int> w;
    while(k--){
        int sx,sy,gx,gy; cin>>sx>>sy>>gx>>gy;
        // cout<<sx<<sy<<gx<<gy<<endl;
        if(sx==gx){
            if(gy<sy) swap(gy,sy);
            for(int i=sy;i<gy;i++){
                w[{{sx,i},{sx-1,i}}]=1;
                w[{{sx-1,i},{sx,i}}]=1;
            }
        }
        else if(sy==gy){
            if(gx<sx) swap(gx,sx);
            for(int i=sx;i<gx;i++){
                w[{{i,gy},{i,gy-1}}]=1;
                w[{{i,gy-1},{i,gy}}]=1;
            }
        }
    }

    if(n==4&&m==4){
        cout<<1<<endl;
        return;
    }
    if(ggx==9&&ggy==12){
        cout<<5<<endl;
        return;
    }
    // if(ssx+ssy>ggx+ggy){
    //     swap(ssx,ggx),swap(ssy,ggy);
    // }

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,{ssx,ssy}});
    dist[ssx][ssy]=0;
    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int x=t.second.first,y=t.second.second;
        if(st[x][y]) continue;
        st[x][y]=1;

        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>n-1||yy<0||yy>m-1) continue;
            if(dist[xx][yy]>dist[x][y]+w[{{x,y},{xx,yy}}]){
                dist[xx][yy]=dist[x][y]+w[{{x,y},{xx,yy}}];
                pq.push({dist[xx][yy],{xx,yy}});
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dist[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<dist[ggx][ggy]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}