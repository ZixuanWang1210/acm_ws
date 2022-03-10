#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4+10;
int h[maxn],ne[maxn],e[maxn],idx;
int n,m,ans,res;
int match[maxn];
bool st[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int u){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(!match[j]||find(match[j])){
                match[j]=u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    int u,v;
    memset(h,-1,sizeof h);
    while(cin>>u>>v,u!=-1){
        add(u,v);
    }

    for(int i=1;i<=m;i++){
        memset(st,0,sizeof st);
        // cout<<find(i)<<endl;
        if(find(i)) res++;
    }

    cout<<res<<endl;
    for(int i=1;i<=m;i++){
        if(match[i]){
            cout<<i<<' '<<match[i]<<endl;
        }
    }

    return 0;
}