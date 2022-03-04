#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
int h[maxn],e[maxn],ne[maxn],idx;
int din[maxn];
int n,k,ans,cnt;

void sol(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(din[i]==1){
            q.push(i);
            din[i]=0;
        }
    }
    while(cnt<=n-k){
        ans++;
        queue<int> temp;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            if(cnt==n-k) return;
            for(int i=h[u];~i;i=ne[i]){
                // cout<<1<<endl;
                int j=e[i];
                din[j]--;
                if(din[j]==1){
                    din[j]=0;
                    temp.push(j);
                }
            }
        }
        q=temp;
    }
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){
    cin>>n>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
        din[u]++,din[v]++;
    }
    sol();
    cout<<ans;

    return 0;
}