#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int n,m,c,res;
int h[maxn],ne[maxn],e[maxn],idx;
int match[maxn];
bool st[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int find(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(!match[j]||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m>>c;
    memset(h,-1,sizeof h);
    for(int i=1;i<=c;i++){
        int u,v; cin>>u>>v;
        add(u,v);
    }

    for(int i=1;i<=n;i++){
        memset(st,0,sizeof st);
        if(find(i)){
    // cout<<2<<endl;
            res++;
        }
    }

    cout<<res<<endl;
    // for(int i=1;i<=m;i++){
    //     if(match[i]){
    //         cout<<i<<' '<<match[i]<<endl;
    //     }
    // }
    return 0;
}