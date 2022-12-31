#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
// #define ll long long
#define int long long

using namespace std;

int n,m,K;
const int maxn=2e5+10;
int a[maxn];
int t[maxn];
map<int,int> mp;
int ans=0;
int s[maxn];

void sol(){
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int l=1,r=0;
    int cnt=0;
    for(r=1;r<=n;r++){
        if(++mp[a[r]]==1) cnt++;
        while(cnt==K){
            t[l]=r;
            if(--mp[a[l]]==0) cnt--;
            l++;
        }
    }
    // while(l<=n&&r<n){
    //     r++;
    //     if(!mp[a[r]]){
    //         cnt++;
    //     }
    //     mp[a[r]]++;
        
    //     if(cnt==K){
    //         if(a[l]!=a[r]) t[l]=r;
    //         while(cnt==K){
    //             if(mp[a[l]]){ 
    //                 mp[a[l]]--;
    //                 if(mp[a[l]]==0) cnt--;
    //             }
    //             l++;
    //             if(cnt==K) t[l]=r;
    //         }
    //     }
    //     else t[l]=r;
    // }
    for(int i=1;i<=n;i++) if(!t[i]) t[i]=n+1;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+t[i];
    }
    // for(int i=1;i<=n;i++) cout<<t[i]<<' ';
    // cout<<endl;
    while(m--){
        int ll,rr; cin>>ll>>rr;
        int l=min(ll^ans,rr^ans)+1;
        int r=max(ll^ans,rr^ans)+1;
        // cout<<l<<' '<<r<<endl;
        rr=upper_bound(t+1,t+1+n,r)-t-1;
        if(rr<l) ans=0;
        else ans=(r+1)*(rr-l+1)-(s[rr]-s[l-1]);
        cout<<ans<<endl;
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
