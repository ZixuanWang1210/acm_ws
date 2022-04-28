#include<bits/stdc++.h>
using namespace std;

const int maxn=5e4+10;
int n,fsum[maxn];
int e[maxn],ne[maxn],h[maxn],idx;
int d1[maxn],s2[maxn],res;
bool st[maxn];
int ans;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u){
    st[u]=true;
    int dis=0;
    int d1=0,d2=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            int d=dfs(j);
            dis=max(dis,d);
            if(d>=d1) d2=d1,d1=d;
            else if(d>d2) d2=d;
        }
    }
    ans=max(ans,d1+d2);
    return dis+1;
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n/i;j++){
            fsum[i*j]+=i;
        }
    }

    for(int i=2;i<=n;i++){
        if(fsum[i]<i){
            add(fsum[i],i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!st[i])
        dfs(i);
    }
    cout<<ans<<endl;
    return 0;
}