#include<bits/stdc++.h>
using namespace std;

const int N=3000;
int e[N],ne[N],w[N],h[N],idx;
int dis[N];
int n,p,c;
int id[N];
bool st[N];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa(int s){
    queue<int>q;
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    q.push(s);
    st[s]=true;
    dis[s]=0;
    while(q.size()){
        int t=q.front();q.pop();st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                if(!st[j]){
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        int j=id[i];
        if(dis[j]==0x3f3f3f3f) return 0x3f3f3f3f;
        res+=dis[j];
    }
    return res;
}

int main(){
    cin>>n>>p>>c;
    for(int i=1;i<=n;i++) cin>>id[i];
    
    memset(h,-1,sizeof h);
    for(int i=1;i<=c;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    
    int res=0x3f3f3f3f;
    for(int i=1;i<=p;i++) res=min(res,spfa(i));
    cout<<res<<endl;

    return 0;
}