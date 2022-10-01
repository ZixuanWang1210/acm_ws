#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<long long,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=600010;
const int maxm=2000010;
int h[maxn],ne[maxm],e[maxm],w[maxm],idx;
int n,m;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

ll dis[maxn];
bool st[maxn];
void dij(){
    memset(dis,0x7f,sizeof dis);
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dis[1]=0;
    pq.push({0,1});

    while(pq.size()){
        auto t=pq.top();pq.pop();
        ll d=t.first,ver=t.second;
        if(st[ver]) continue;
        st[ver]=true;

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>d+w[i]){
                dis[j]=d+w[i];
                pq.push({dis[j],j});
            }
        }
    }
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        add (u, v, w), add(v, u, w);
		add (u + n, v + n, w), add(v + n, u + n, w);
		add (u + 2 * n, v + 2 * n, w), add (v + 2 * n, u + 2 * n, w);
		add (u + 3 * n, v + 3 * n, w), add (v + 3 * n, u + 3 * n, w);
		
		add (u, v + n, 2 * w), add (v, u + n, 2 * w);
		add (u + n, v + 3 * n, 0), add(v + n, u + 3 * n, 0);
		
		add (u, v + 2 * n, 0), add (v, u + 2 * n, 0);
		add (u + 2 * n, v + 3 * n, 2 * w), add (v + 2 * n, u + 3 * n, 2 * w);
    }

    dij();

    for(int i=2;i<=n;i++){
        cout<<min(dis[i+3*n],dis[i])<<' ';
    }
    cout<<endl;

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
