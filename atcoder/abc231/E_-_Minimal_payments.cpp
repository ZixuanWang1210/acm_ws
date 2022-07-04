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

int n,x;
const int maxn=100;
int v[maxn];
int res;

int cc(int x){
    if(x==0) return 0;
    int rr=*prev(upper_bound(v+1,v+1+n,x));
    res+=x/rr;
    x%=rr;
    cc(x);
    return res;
}

void sol(){
    cin>>n;
    cin>>x;
    for(int i=1;i<=n;i++) cin>>v[i];

    res=0;
    int ans1=cc(x);
    int cost=*lower_bound(v+1,v+1+n,x);
    int ans2=inf;
    res=0;
    if(cost>=x){
        ans2=1+cc(cost-x);
    }
    // cout<<min(ans1,ans2)<<endl;
    cout<<ans1<<" "<<ans2<<endl;

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
