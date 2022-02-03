#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define root tr[u]
#define ls tr[u<<1] 
#define rs tr[u<<1|1]
using namespace std;

const int N=100010;
int n;
struct Edge{
    double x,y1,y2;
    int v;
    bool operator<(const Edge &t) const{
        return x<t.x;
    }
}edge[2*N];

struct node{
    int l,r;
    int cnt;
    double len;
} tr[8*N];

vector<double> ys;

int find(double x){//注意数据类型！！！
    return lower_bound(ys.begin(),ys.end(),x)-ys.begin();
}

void pushup(int u){
    if(root.cnt) root.len=ys[root.r+1]-ys[root.l];
    else if(root.l !=root.r){
        root.len=rs.len+ls.len;
    }
    else root.len=0;
}

void build(int u,int l,int r){
    if(l==r) root={l,r,0,0};
    else{
        root={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        // pushup(u);
    }
}

void modify(int u,int l,int r,int k){
    if(root.l>=l&&root.r<=r){
        root.cnt+=k;
        pushup(u);
    }
    else{
        int mid=root.r+root.l>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // cin>>n;
    int T=1;
    while(cin>>n,n){
        int idx=0;
        ys.clear();
        for(int i=0;i<n;i++){
            double x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            edge[idx++]={x1,y1,y2,1};
            edge[idx++]={x2,y1,y2,-1};
            ys.push_back(y1),ys.push_back(y2);
        }

        sort(ys.begin(),ys.end());
        ys.erase(unique(ys.begin(),ys.end()),ys.end());

        build(1,0,ys.size()-2);

        sort(edge,edge+n*2);

        double ans=0;
        for(int i=0;i<n*2;i++){
            if(i>0) ans+=tr[1].len*(edge[i].x-edge[i-1].x);
            modify(1,find(edge[i].y1),find(edge[i].y2)-1,edge[i].v);
        }

        cout<<"Test case #"<<T++<<endl;
        cout<<"Total explored area: "<<fixed<<setprecision(2)<<ans<<endl<<endl;
    }

    return 0;
}
