#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5;
int h[maxn],ne[maxn],e[maxn],idx;
int match[maxn];
bool st[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void init(){
    idx=0;
    memset(h,-1,sizeof h);
    memset(e,0,sizeof e);
    memset(ne,0,sizeof ne);
    memset(st,0,sizeof st);
    memset(match,0,sizeof match);
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

void sol(){
    init();
    int n; cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t; cin>>t;
            if(t){
                add(i,j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(st,0,sizeof st);
        if(find(i)) ans++;
    }

    // for(int i=1;i<=n;i++){
    //     if(match[i]==0){
    //         cout<<"No"<<endl;
    //         return;
    //     }
    // }
    // cout<<"Yes"<<endl;
    // return;
    // cout<<ans<<endl;
    if(ans==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
