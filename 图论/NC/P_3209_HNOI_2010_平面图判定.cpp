#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=8e6;
int p[maxn];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void sol(){
    int n,m; cin>>n>>m;
    // for(int i=1;i<=n;i++) p[i]=i;

    struct seg{
        int u,v;
    };
    vector<seg> vec(m+1);
    vector<bool> st(m+1,0);

    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        // vec.push_back({u,v});
        vec[i]={u,v};
    }

    // map<int,int> mp;
    vector<int> id(n+1,0);
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        id[x]=i;
    }
    if(m>3*n-6){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=1;i<=m;i++){
        auto x=vec[i];
        x.u=id[x.u];
        x.v=id[x.v];
        if(x.u>x.v) swap(x.u,x.v);
        cout<<x.u<<' '<<x.v<<endl;
    }

    for(int i=1;i<=m;i++){
        auto x=vec[i];
        if(x.v==x.u+1||(x.v==n&&x.u==0)) st[i]=true;
    }

    auto cross=[&](seg x,seg y){
        int x1=x.u,x2=y.u,y1=x.v,y2=y.v;
        if( x1 == x2 || y1 == y2 || x1 == y2 || x2 == y1 )
            return 0;
        if( x1 < x2 && y1 < y2 && x2 < y1 )
            return 1;
        if( x2 < x1 && y2 < y1 && x1 < y2 )
            return 1;
        return 0;
    };

    auto check=[&](){
        for(int i=0;i<=m<<1;i++) p[i]=i;

        for(int i=1;i<=m;i++){
            if(st[i]) continue;
            for(int j=1;j<=m;j++){
                if(st[j]) continue;
                if(!cross(vec[i],vec[j])) continue;
                int fi=find(i),fj=find(j);
                if(fi==fj) return 0;
                p[fi]=find(j+m),p[fj]=find(i+m);
            }
        }
        return 1;
    };

    if(check()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
