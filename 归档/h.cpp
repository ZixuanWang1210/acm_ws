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

struct node{
    int p,v,t;
    int id;
    int pos;
    bool operator<(const node &t) const{
        return p<t.p;
    }
};
struct node1{
    int p,v,t;
    int id;
    int pos;
    bool operator<(const node1 &t) const{
        return pos<t.pos;
    }
};
const int maxn=1e5+10;
int qian[maxn],hou[maxn];
node v[maxn];
node1 tmp[maxn];
int n,k;
pii seg[maxn];

void sol(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        node tt;
        cin>>tt.p>>tt.v>>tt.t;
        v[i]=tt;
    }
    if(k==1){
        cout<<-1<<endl;
        return;
    }
    sort(v+1,v+1+n);
    for(int i=1;i<=n;i++){
        tmp[i].t=v[i].t;
        tmp[i].v=v[i].v;
        tmp[i].p=v[i].p;
    }

    for(int i=1;i<=n;i++){
        tmp[i].id=v[i].id=i;
    }

    seg[1].first=1,seg[n].second=n;
    for(int i=2;i<=n;i++){
        if(v[i].t==v[i-1].t) seg[i].first=seg[i-1].first;
        else seg[i].first=i;
    }
    for(int i=n-1;i;i--){
        if(v[i].t==v[i+1].t) seg[i].second=seg[i+1].second;
        else seg[i].second=i;
    }

    auto check=[&](int t){
        for(int i=1;i<=n;i++){
            tmp[i].pos=tmp[i].p+1ll*tmp[i].v*t;
        }
        sort(tmp+1,tmp+1+n);
        bool ok=1;
        for(int i=1;i<=n;i++){
            if(i!=1&&tmp[i-1].pos==tmp[i].pos&&tmp[i].t!=tmp[i-1].t){
                ok=0;
                break;
            }
            if((i<seg[tmp[i].id].first||i>seg[tmp[i].id].second)){
                ok=0;
                break;
            }
        }
        return ok;
    };

    ll l=0,r=1e10;
    while(l<r){
        ll mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    if(l==1e10) cout<<-1<<endl;
    else cout<<l<<endl;

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
