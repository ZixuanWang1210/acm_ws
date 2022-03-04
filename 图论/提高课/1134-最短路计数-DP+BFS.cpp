#include<bits/stdc++.h>
#define pii pair<int,int>
#define P 100003
using namespace std;

const int maxn=2e7+10;
int h[maxn],ne[maxn],e[maxn],idx;
int n,m;
int cnt[maxn];
int dis[maxn];
bool st[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dij(){
    memset(dis,0x3f,sizeof dis);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    dis[1]=0;
    cnt[1]=1;

    while(pq.size()){
        int t=pq.top().second,dist=pq.top().first;
        pq.pop();
        if(st[t]) continue;
        st[t]=true;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dist+1){
                dis[j]=dist+1;
                cnt[j]=cnt[t];
                pq.push({dis[j],j});
            }
            else if(dis[j]==dist+1){
                cnt[j]=(cnt[t]+cnt[j])%P;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
    }

    dij();

    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<endl;
    }

    return 0;
}