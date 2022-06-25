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

const int maxn=1e5+10;
int f[maxn],s[maxn];
int n,m; 
bool check(int x){
    int  sum=0;
    for(int i=1;i<=n;i++){
        if(s[i]>x) sum=0;
        else sum+=f[i];
        if(sum>=m) return true;
    }
    return false;
}

void sol(){
    cin>>n>>m;
    int r;
    for(int i=1;i<=n;i++) cin>>f[i]>>s[i],r=max(r,s[i]);

    int l=1;
    int ans=0;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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
