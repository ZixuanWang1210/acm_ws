#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int maxn=1e5+10;
int p[maxn];
int n;

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void sol(int n){
    vector<pii> v(2*n);
    int _max=-1;

    for(int i=1;i<=n;i++){
        int u,e; cin>>u>>e;
        // cin>>v[i].first>>v[i].second;
        v[i].first=-u;
        v[i].second=e;
        _max=max(_max,e);
    }
    sort(v.begin()+1,v.begin()+1+n);
    for(int i=1;i<=_max;i++) p[i]=i;

    int res=0;
    for(int i=1;i<=n;i++){
        int cost=-v[i].first,ver=v[i].second;
        ver=find(ver);
        if(ver>0){
            res+=cost;
            p[ver]--;
        }
    }
    cout<<res<<endl;

}

int main(){
    while(cin>>n){
        sol(n);
    }

    return 0;
}