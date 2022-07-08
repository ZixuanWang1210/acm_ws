#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 3e18
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=3e6+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int n,m,S,T;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int d[maxn],cur[maxn];
bool bfs(){
    memset(d,-1,sizeof d);
    queue<int> q;
    d[S]=0,cur[S]=h[S];
    q.push(S);
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(d[j]==-1&&w[i]){
                d[j]=d[t]+1;
                cur[j]=h[j];
                if(j==T) return true;
                q.push(j);
            }
        }
    }
    return false;
}

int find(int u,int limit){
    if(u==T) return limit;
    int flow=0;

    for(int i=cur[u];~i;i=ne[i]){
        cur[u]=i;
        int j=e[i];
        if(d[j]==d[u]+1&&w[i]){
            int t=find(j,min(w[i],limit-flow));
            if(!t) d[j]=-1;
            w[i]-=t,w[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

int dinic(){
    int res=0,flow;
    while(bfs()){
        while(flow=find(S,inf)) res+=flow;
    }
    return res;
}

void sol(){
    cin>>n>>m>>S>>T;
    memset(h,-1,sizeof h);
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        add(u,v,c),add(v,u,0);
    }

    int ans=dinic();
    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
