#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=10+10,M=20+10;
int h[N],ne[M],e[M],idx;
int n,m;
int st[N],ans[N],dis[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void bfs(){
    queue<pii> q;
    memset(dis,0x3f,sizeof dis);
    st[1]=true;
    q.push({1,0});
    ans[1]=1;
    dis[1]=0;

    while(q.size()){
        int t=q.front().first, dist=q.front().second;
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(!st[j]){
                st[j]=true;
                ans[j]+=ans[t];
                dis[j]=dist+1;
                cout<<dist<<endl;
                cout<<j<<' '<<dist+1<<endl;
                q.push({j,dist+1});
            }
            else{
                if(dist+1==dis[j]) ans[j]+=ans[t];
            }
        }
    }

    
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        if(a==b) continue;
        add(a,b),add(b,a);
    }

    bfs();

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}