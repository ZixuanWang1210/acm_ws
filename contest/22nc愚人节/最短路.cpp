#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>
using namespace std;


const int maxn=1e5+10;
struct node{
    int u,v;
    double w;
    bool operator<(const node &t) const{
        return w<t.w;
    }
} edge[maxn];
int p[maxn],idx;

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

double get(pii a,pii b){
    double dx=a.first-b.first;
    double dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a,b,c,d; cin>>a>>b>>c>>d;
    int n; cin>>n;
    vector<pii> v;
    for(int i=1;i<=a+b+c+d;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    for(int i=0;i<=a+b+c+d;i++){
        p[i]=i;
    }

    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            edge[++idx]={i,j,get(v[i],v[j])};
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        edge[++idx]={0,idx,sqrt(x*x+y*y)};
        p[idx]=0;
        cnt++;
    }

    sort(edge+1,edge+1+idx);

    double res=0;
    for(int i=1;i<=idx;i++){
        int u=edge[i].u,v=edge[i].v;
        double dis=edge[i].w;
        u=find(u),v=find(v);
        if(u!=v){
            cnt++;
            res+=dis;
            if(cnt==n-1){
                cout<<res;
                return 0;
            }
        }

    }

    return 0;
}
