#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;

const int M=6e6+10,N=1e6+10;
int h[N],e[M],ne[M],w[M],idx;
int dis[N];
bool st[N];
int cost[N];
int n,m,b;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool check(int x){
    if(cost[1]>x) return 0;
    memset(st,0,sizeof st);
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});

    while(pq.size()){
        int t=pq.top().second, dist=pq.top().first;
        pq.pop();
        if(st[t]) continue;
        st[t]=true;

        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(cost[j]>x) continue;
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                pq.push({dis[j],j});
            }
            if(j==n){
                if(dis[n]>=b) return 0;
                else return 1;
            }
        }
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>b;
    int _max=-1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int b; cin>>b;
        cost[i]=b;
        _max=max(_max,cost[i]);

    }

    for(int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
        // cout<<i<<endl;
    }


    int l=1,r=_max,ans=-1;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if(ans==-1) cout<<"AFK"<<endl;
    else cout<<ans<<endl;

    return 0;
}