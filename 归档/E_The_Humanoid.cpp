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

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(all(v));
    int now=k;
    int res=0;
    int d1=2,d2=1;
    int ans=0;
    vector<int> vv[]={{2,2,3},{3,2,2},{2,3,2},{4,3},{3,4},{6,2},{2,6},{12}};
    for(int ii=0;ii<8;ii++){
        now=k;
        res=0;
        int idx=0;
        for(int i=1;i<=n;i++){
            if(v[i]<now) {
                res++;
                now+=v[i]/2;
            }
            else if(idx<vv[ii].size()&&now*vv[ii][idx]>v[i]){
                now*=vv[ii][idx];
                idx++;
                now+=v[i]/2;
                res++;
            }
            else break;
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;

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
