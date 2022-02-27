#include<bits/stdc++.h>
using namespace std;

int t,r,p,s;
const int N=25000+10,M=5000+10;
int h[N],ne[M],e[M],w[M],idx;
int bcnt;
int id[N];
vector<int> block[N];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int bcnt){
    
}

int main(){
    cin>>t>>r>>p>>s;
    memset(h,-1,sizeof h);
    for(int i=1;i<=r;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }

    for(int i=1;i<=t;i++){
        if(!id[i]){
            bcnt++;
            dfs(1,bcnt);
        }
    }


    return 0;
}