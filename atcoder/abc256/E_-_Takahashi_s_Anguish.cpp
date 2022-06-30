#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=2e5+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int c[maxn],x[maxn];
int din[maxn];
int n;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}


bool st[maxn];
int dfs(int u){
    int res=inf;
    queue<int> q;
    q.push(u);

    while(q.size()){
        int t=q.front();
        q.pop();

        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(st[j]) continue;
            st[j]=true;
            res=min(res,w[i]);
            q.push(j);
        }
    }
    return res;
}

void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) cin>>c[i];

    for(int i=1;i<=n;i++){
        add(i,x[i],c[i]);
        din[x[i]]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(din[i]==0) q.push(i);
    }

    while(q.size()){
        int t=q.front();
        q.pop();

        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            din[j]--;
            if(din[j]==0) q.push(j);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<din[i]<<' ';
    // }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(din[i]&&!st[i]){
            // cout<<dfs(i)<<endl;
            ans+=dfs(i);
        }
    }

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
