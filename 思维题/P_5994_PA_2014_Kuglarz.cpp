#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
#define int long long

using namespace std;

const int maxn=2e3+10;
struct node{
    int l,r,w;
    bool operator<(const node& t) const{
        return w<t.w;
    }
} seg[maxn*maxn];
int n;

int p[maxn];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void sol(){
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x; cin>>x;
            seg[++cnt]={i-1,j,x};
        }
    }    
    sort(seg+1,seg+1+cnt);

    for(int i=0;i<=n;i++) p[i]=i;

    int ans=0;
    for(int i=1;i<=cnt;i++){
        int x=seg[i].l,y=seg[i].r;
        int xx=find(x),yy=find(y);

        if(xx!=yy){
            p[xx]=yy;
            // cout<<i<<' '<<x<<' '<<seg[i].w<<endl;
            ans+=seg[i].w;
        }
    }
    cout<<ans<<endl;
    return;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
