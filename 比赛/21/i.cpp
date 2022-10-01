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

struct node{
    int u,v;
    double w;
    bool operator<(const node &t) const{
        return w<t.w;
    }
};

const int maxn=1000;
int p[maxn];

int find(int x){
    if(x!=p[x]) return p[x]=find(p[x]);
    return p[x];
}

void sol(){
    int n; cin>>n;
    vector<pii> v;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }

    auto get=[&](pii a,pii b){
        double dx=a.first-b.first;
        double dy=a.second-b.second;
        return sqrt(dx*dx+dy*dy);
    };

    vector<node> seg;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dis=get(v[i],v[j]);
            if(dis>=10&&dis<=1000) seg.push_back({i,j,dis});
        }
    }

    for(int i=0;i<=n;i++) p[i]=i;
    sort(_all(seg));
    double res=0;
    for(auto x:seg){
        int xx=find(x.u),yy=find(x.v);
        if(xx!=yy){
            p[xx]=yy;
            res+=x.w;
        }
    }
    for(int i=0;i<n;i++){
        if(find(i)!=find(0)){
            cout<<"oh!"<<endl;
            return;
        }
    }
    cout<<fixed<<setprecision(1)<<res*100<<endl;

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
