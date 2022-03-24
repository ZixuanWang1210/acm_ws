#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5+10;
int n,k;
int h[maxn],w[maxn],ne[maxn],e[maxn],idx;
int dis[maxn],pre[maxn];
bool st[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int bfs(int u){
    memset(st,0,sizeof st);
    memset(dis,0,sizeof dis);
    pre[u]=-1;
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
            pre[j]=i;
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

int d1[maxn], d2[maxn], diam;
void dfs(int u, int fa)
{
    d1[u] = d2[u] = 0;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == fa)  continue;
        dfs(j, u);

        diam = max(diam, d1[u] + d1[j] + w[i]);

        if(d1[j] + w[i] > d1[u])  d2[u] = d1[u], d1[u] = d1[j] + w[i];
        else if(d1[j] + w[i] > d2[u])  d2[u] = d1[j] + w[i];
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int a,b; cin>>a>>b;
        add(a,b,1),add(b,a,1);
    }

    int st=bfs(1);
    int ed=bfs(st);

    int res=2*(n-1)-dis[ed]+1;

    if(k==1){
        cout<<res<<endl;
        return 0;
    }
    int u=ed;
    while(u!=st){
        w[pre[u]]=w[pre[u]^1]=-1;
        u=e[pre[u]^1];
    }
    dfs(1,-1);
    res=res-diam+1;
    cout<<res;


    return 0;
}
