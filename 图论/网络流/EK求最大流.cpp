#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=210;
int h[maxn],f[maxn],e[maxn],ne[maxn],idx;
int d[maxn],pre[maxn];
bool st[maxn];

int n,m,S,T;

void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool bfs(){
    memset(st,0,sizeof st);
    queue<int> q;
    q.push(S);
    // st[S]=1;
    d[S]=inf;
    while(q.size()){
        int u=q.front();
        q.pop();

        for(int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if(!st[j]&&f[i]>0){
                st[j]=1;
                d[j]=min(d[u],f[i]);
                pre[j]=i;
                q.push(j);
                if(j==T) return true;
            }
        }
    }
    return false;
}

int EK(){
    int res=0;
    while(bfs()){
        res+=d[T];
        for(int i=T;i!=S;i=e[pre[i]^1]){
            f[pre[i]]-=d[T],f[pre[i]^1]+=d[T];
        }
    }
    return res;
}

void sol(){
    cin>>n>>m>>S>>T;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,0);
    }
    cout<<EK();
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
