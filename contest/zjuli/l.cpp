#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int maxn=6e7;
int ne[maxn],e[maxn],h[maxn],w[maxn],idx;
int m,n,k,q;
bool st[maxn];

struct node{
    int v;
    map<int,int> a;
};

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void erase(int a,int b){
    ne[a]=ne[b];
}

void init(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<k-1;j++){
            add(i+j*n,i+(j+1)*n,0);
            add(i+(j+1)*n,i+j*n,0);
        }
    }
}

int dfs(int ss,int tt){
    queue<node> q;
    memset(st,0,sizeof st);
    node temp={ss};
    q.push(temp);
    while(q.size()){
        auto t=q.front();q.pop();
        int ver=t.v;
        auto now=t.a;
        
        // if(st[ver]) continue;
        // st[ver]=true;
        // erase()

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            // if(st[j]) continue;
            int kind=w[i];
            auto re=now;
            re[w[i]]+=1;

            q.push({j,re});
            erase(ver,j);
            if(j==(tt+(k-1)*n)){
                int bijiao=re[1];
                bool bz=true;
                for(int ii=1;ii<=k;ii++){
                    if(bijiao!=re[ii]) bz=false;
                }
                if(bz) return true;
            }
            else{
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>q;
    memset(h,-1,sizeof h);
    init();
    for(int i=1;i<=m;i++){
        int u,v,t; cin>>u>>v>>t;
        // if(u==v) continue;
        add(u+(t-1)*n,v+(t-1)*n,t),add(v+(t-1)*n,u+(t-1)*n,t);
    }

    while(q--){
        int s,t;
        cin>>s>>t;
        
        if(dfs(s,t)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    

    return 0;
}
