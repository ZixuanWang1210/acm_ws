#include<bits/stdc++.h>
using namespace std;

const int maxn=5e6+10;
int p[maxn],d[maxn],n,_min,re;

int find(int x){
    if(x!=p[x]){
        int last=p[x];
        p[x]=find(p[x]);
        d[x]+=d[last];
    };
    return p[x];
}

void merge(int a,int b){
    int x=find(a),y=find(b);
    if(x!=y){
        p[x]=y;
        d[a]=d[b]+1;
    }
    else _min=min(_min,d[a]+d[b]+1);
    return;
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) p[i]=i;
    _min=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        merge(i,t);
    }
    cout<<_min<<endl;

    return 0;
}