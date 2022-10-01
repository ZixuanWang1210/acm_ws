#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define x first
#define y second
using namespace std;

const int maxn=5e7+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dis[maxn];
bool st[maxn];
int n,m;
bool cmpx(pii a,pii b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmpy(pii a,pii b){
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}
vector<pii> v;
map<pii,int> mp;
int cnt;
int sx,sy,gx,gy;

int dij(){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,mp[{sx,sy}]});
    dis[mp[{sx,sy}]]=0;

    while(pq.size()){
        auto t=pq.top();pq.pop();
        int d=t.first,ver=t.second;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>d+w[i]){
                dis[j]=d+w[i];
                pq.push({dis[j],j});
            }
        }
    }
    int res=min(dis[mp[{gx,gy}]],dis[mp[{gx,gy}]+cnt]);
    if(res==0x3f3f3f3f) return false;
    else return res;
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
        if(!mp[{x,y}]) mp[{x,y}]=++cnt;
    }
    cin>>sx>>sy>>gx>>gy;
    if(!mp[{sx,sy}]) mp[{sx,sy}]=++cnt;
    if(!mp[{gx,gy}]) mp[{gx,gy}]=++cnt;
    for(auto x:v){
        add(mp[x],mp[x]+cnt,1);
        add(mp[x]+cnt,mp[x],1);
        // cout<<"addz: "<<mp[x]<<' '<<mp[x]+cnt<<' '<<endl;
    }
    v.push_back({sx,sy});
    v.push_back({gx,gy});

    add(mp[{sx,sy}],mp[{sx,sy}]+cnt,0);
    add(mp[{sx,sy}]+cnt,mp[{sx,sy}],0);
    add(mp[{gx,gy}],mp[{gx,gy}]+cnt,0);
    add(mp[{gx,gy}]+cnt,mp[{gx,gy}],0);

    sort(_all(v),cmpx);
    for(int i=1;i<v.size();i++){
        if(v[i].x!=v[i-1].x) continue;
        add(mp[v[i]],mp[v[i-1]],2*abs(v[i].y-v[i-1].y));
        add(mp[v[i-1]],mp[v[i]],2*abs(v[i].y-v[i-1].y));
        // cout<<"addx: "<<mp[v[i]]<<' '<<mp[v[i-1]]<<' '<<2*abs(v[i].y-v[i-1].y)<<endl;
    }

    sort(_all(v),cmpy);
    for(int i=1;i<v.size();i++){
        if(v[i].y!=v[i-1].y) continue;
        add(mp[v[i]]+cnt,mp[v[i-1]]+cnt,2*abs(v[i].x-v[i-1].x));
        add(mp[v[i-1]]+cnt,mp[v[i]]+cnt,2*abs(v[i].x-v[i-1].x));
        // cout<<"addy: "<<mp[v[i]]+cnt<<' '<<mp[v[i-1]]+cnt<<' '<<2*abs(v[i].x-v[i-1].x)<<endl;
    }
    int res=dij();
    if(res==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    while(_--){
        sol();
    }

    return 0;
}
