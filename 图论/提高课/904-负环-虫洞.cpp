#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5+10;
int e[maxn],ne[maxn],h[maxn],idx;
int n,m,W;
int w[maxn];
int dis[maxn],cnt[maxn]; //多加
bool st[maxn];


void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx ++;
}

bool spfa(){
    memset(dis,0,sizeof dis);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);

    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
        st[i]=true;
    }

    while(q.size()){
        int t=q.front(); q.pop();
        st[t]=false;
        
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int f;cin>>f;
    while(f--){
        cin>>n>>m>>W;
        memset(h,-1,sizeof h);
        while(m--){
            int s,e,t; cin>>s>>e>>t;
            add(s,e,t),add(e,s,t);
        }
        while(W--){
            int s,e,t; cin>>s>>e>>t;
            add(s,e,-t);
        }

        if(spfa()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    

    return 0;
}
