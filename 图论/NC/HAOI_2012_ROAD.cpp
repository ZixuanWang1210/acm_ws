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

const int maxn=5e5+10;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int n,m;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
struct seg{
    int u,v,w;
};
vector<seg> vec;
int dis[maxn];
bool st[maxn];
int ans[maxn];
int f[maxn];
void spfa(int s){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    queue<int> q;
    q.push(s),st[s]=1;dis[s]=0;

    while(q.size()){
        int t=q.front(); q.pop(); st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
}

// void top(int s){
//     // path.push_back(s);
//     vector<bool> in_path(n+1);
//     vector<int> d(n+1);
//     vector<int> path;

//     vector<int> cnt1(n+1),cnt2(n+1);
//     cnt1[s]=1;
//     for(int i=0;i<vec.size();i++){
//         auto x=vec[i];
//         int u=x.u,v=x.v,w=x.w;
//         if(dis[u]+w==dis[v]) d[v]++,in_path[i]=1;
//     }

//     queue<int> q;
//     q.push(s);
//     while(q.size()){
//         int t=q.front(); q.pop();
//         path.push_back(t);
//         for(int i=h[t];~i;i=ne[i]){
//             int j=e[i];
//             d[j]--;
//             if(d[j]==0&&in_path[i]){
//                 q.push(j);
//                 cnt1[j]=(cnt1[t]+cnt1[j])%mod;
//             }
//         }
//     }
//     for(int i=path.size()-1;i>=0;i--){
//         int u=path[i];
//         cnt2[u]++;
//         for(int j=h[u];~j;j=ne[j]){
//             int jj=e[j];
//             if(!in_path[j]) continue;
//             cnt2[u]=(cnt2[jj]+cnt2[u])%mod;
//         }
//     }

//     cout<<endl;
//     cout<<"S: "<<endl;
//     // for(auto x:path){
//     //     cout<<x<<" ";
//     // }
//     for(int i=1;i<=n;i++){
//         cout<<cnt2[i]<<' ';
//     }
//     cout<<endl;

//     for(int i=0;i<m;i++){
//         auto x=vec[i];
//         int u=x.u,v=x.v,w=x.w;
//         (ans[i]+=(1ll)*cnt1[u]*cnt2[v])%=mod;
//     }
// }

void top(int s){
    memset(f,0,sizeof f);
    for(int i=0;i<vec.size();i++){
        int u=vec[i].u,v=vec[i].v,w=vec[i].w;
        if(dis[u]+w==dis[v]) f[i]=1;
    }
    vector<int> path;
    vector<int> d(n+1);
    queue<int> q;
    q.push(s);

    for(int i=0;i<vec.size();i++){
        if(f[i]) d[e[i]]++;
    }
    vector<int> cnt1(n+1),cnt2(n+1);
    cnt1[s]=1;
    while(q.size()){
        int t=q.front(); q.pop();
        path.push_back(t);

        for(int i=h[t];~i;i=ne[i]){
            if(!f[i]) continue;
            int j=e[i];
            d[j]--;
            if(d[j]==0) q.push(j);
            cnt1[j]=(cnt1[j]+cnt1[t])%mod;
        }
    }
    // for(int i=1;i<=n;i++) cout<<cnt1[i]<<' ';
    // cout<<endl;

    for(int i=path.size()-1;i>=0;i--){
        int t=path[i];
        cnt2[t]++;
        for(int j=h[t];~j;j=ne[j]){
            if(!f[j]) continue;
            int jj=e[j];
            cnt2[t]=(cnt2[t]+cnt2[jj])%mod;
        }
    }

    for(int i=0;i<vec.size();i++){
        int u=vec[i].u,v=vec[i].v,w=vec[i].w;
        if(f[i]) (ans[i]+=(1ll)*cnt1[u]*cnt2[v])%=mod ;
    }
}

void sol(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w);
        // in_path[i]=1;
        vec.push_back({u,v,w});
    }

    for(int i=1;i<=n;i++){
        spfa(i),top(i);
    }

    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;;
    }

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
