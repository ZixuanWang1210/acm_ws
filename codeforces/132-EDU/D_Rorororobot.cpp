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
int n,m;
struct node{
    int l,r,w;
} tr[maxn<<2];
int a[maxn];


#define ls tr[u<<1]
#define rs tr[u<<1|1]
#define rt tr[u]
void pushup(int u){
    rt.w=max(ls.w,rs.w);
}

void build(int u,int l,int r){
    rt={l,r};
    if(l==r){
        rt.w=a[l];
        return;
    }
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}


int query(int u,int l,int r){
    if(rt.l>=l&&rt.r<=r) return rt.w;
    int res=-inf;
    int mid=rt.l+rt.r>>1;
    if(l<=mid) res=max(res,query(u<<1,l,r));
    if(r>mid) res=max(res,query(u<<1|1,l,r));
    return res;
}

void sol(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];

    build(1,1,m);

    int q; cin>>q;
    while(q--){
      int sx,sy,ex,ey,k;
		cin>>sx>>sy>>ex>>ey>>k;
		if((sx-ex)%k||(sy-ey)%k){
			cout<<"NO"<<endl;
			continue;
		}
		sx+=(n-sx)/k*k;

		int maxx=query(1,min(sy,ey),max(sy,ey));
		if(maxx<sx) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
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
