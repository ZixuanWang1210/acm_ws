#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=2e5+10;
int n,m,x,k;
bool st[maxn];
int dis[maxn];
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void sol(){
    cin>>n>>m>>x>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
    pq.push({0,x,1});
    //key 能力值 下标
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;

    while(pq.size()){
        auto [d,xx,ver]=pq.top();
        pq.pop();
        if(st[ver]) continue;
        st[ver]=true;
        dis[ver]=min(dis[ver],d);
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(w[i]<xx) pq.push({d+1,xx,j});
            else{
                int t=(w[i]-xx+k)/k;
                pq.push({d+1+t,t*k+x,j});
            }
        }
    }
    cout<<dis[n]<<endl;
    

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
