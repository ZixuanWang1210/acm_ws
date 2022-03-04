#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e6+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
bool st[maxn];
int dis[maxn],bk_dis[maxn];
int n,m;
int t,ans;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int bfs(int u){
    memset(st,0,sizeof st);
    memset(dis,0,sizeof dis);
    queue<int> q;
    st[u]=true;
    q.push(u);
    int res=0,max_dis=0;
    while(q.size()){
        int ver=q.front(); q.pop();
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(st[j]) continue;
            st[j]=true;
            dis[j]=dis[ver]+w[i];
            q.push(j);
            if(dis[j]>max_dis){
                max_dis=dis[j];
                res=j;
            }
        }
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    int l=bfs(1);
    int r=bfs(l);
    ans=dis[r];
    memcpy(bk_dis,dis,sizeof bk_dis);
    bfs(r);
    int M=0;
    for(int i=1;i<=n;i++){
        M=max(M,min(dis[i],bk_dis[i]));
    }

    cout<<M+ans<<endl;

    return 0;
}