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

int n;
struct node{
    int l,r;
    bool operator<(const node &t) const{
        return l<t.l;
    }
};
int xs,rs;

void sol(){
    cin>>n;
    vector<node> vec;
    for(int i=1;i<=n;i++){
        int xi,ri; cin>>xi>>ri;
        vec.push_back({xi-ri,ri+xi});
    }
    sort(_all(vec));

    int res=vec[0].r;
    int ans=0;
    for(int i=1;i<n;i++){
        if(vec[i].l>res) ans+=vec[i].l-res;
        res=max(res,vec[i].r);
    }

    cout<<ans<<endl;
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
