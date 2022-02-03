#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]
using namespace std;

const int N=1e7+10;
int n,w,h;
struct node{
    int l,r;
    ll data,add;
} tr[8*N];

struct edge{
    int x,y1,y2;
    int k;
    bool operator<(const edge& m) const{
        if(x==m.x) return k<m.k;
        return x<m.x;
    }
} seg[N*2];
vector<int> mp;

void pushup(int u){
    root.data=max(ls.data,rs.data);
}

void pushdown(int u){
    rs.data+=root.add;
    ls.data+=root.add;
    rs.add+=root.add;
    ls.add+=root.add;
    root.add=0;
}

void build(int u,int l,int r){
    root={l,r,0,0};
    if(l==r) return;
    else{
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    }
}

void modify(int u,int l,int r,int add){
    if(root.l>=l&&root.r<=r){
        root.add+=add;
        root.data+=add;
        return;
    }
    else{
        if(root.add) pushdown(u);
        int mid=root.l+root.r>>1;
        if(l<=mid) modify(u<<1,l,r,add);
        if(r>mid) modify(u<<1|1,l,r,add);
        pushup(u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>w>>h;
        int cnt=0;
        mp.clear();
        mp.push_back(-0x3f3f3f3f);
        for(int i=0;i<n;i++){
            int x,y,c; cin>>x>>y>>c;
            seg[cnt++]={x,y,y+h-1,c};
            seg[cnt++]={x+w,y,y+h-1,-c};
            mp.push_back(y); mp.push_back(y+h-1);
        }
        sort(mp.begin(),mp.end());
        mp.erase(unique(mp.begin(),mp.end()),mp.end());
        int num=mp.size()-1;
        for(int i=0;i<cnt;i++){
            seg[i].y1=lower_bound(mp.begin(),mp.end(),seg[i].y1)-mp.begin();
            seg[i].y2=lower_bound(mp.begin(),mp.end(),seg[i].y2)-mp.begin();
        }
        sort(seg,seg+cnt);

        build(1,1,num);

        ll ans=0;
        for(int i=0;i<num;i++){
            modify(1,seg[i].y1,seg[i].y2,seg[i].k);
            ans=max(ans,tr[1].data);
        }
        cout<<ans<<endl;
    }
    return 0;
}
