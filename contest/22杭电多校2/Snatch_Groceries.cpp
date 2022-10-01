#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007

using namespace std;
struct node{
    int l,r;
    bool operator<(const node &t) const{
        if(l==t.l) return r>t.r;
        else return l<t.l;
    }
};

void sol(){
    int n; cin>>n;
    vector<node> v;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }

    sort(_all(v));
    
    int ed=v[0].r;
    int res=0;
    bool ok=false;
    for(int i=1;i<n;i++){
        if(ed<v[i].l) {ed=v[i].r;res++;}
        else {ok=true; break;}
    }
    if(!ok) res++;
    cout<<res<<endl;

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
