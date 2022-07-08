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
int cnt[maxn];
int v[maxn];
int n,m;

bool check(int mid){
    int res=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>mid) res+=2*(cnt[i]-mid);
        else res-=(mid-cnt[i])/2*2;
    }
    if(res<=0) return true;
    else return false;
}

void sol(){
    cin>>n>>m;
    for(int i=0;i<=max(n,m);i++){
        cnt[i]=0;
        v[i]=0;
    }
    // vector<int> v(m+1);
    // map<int,int> mp;
    for(int i=1;i<=m;i++){
        cin>>v[i];
        // mp[v[i]]++;
        cnt[v[i]]++;
    }
    int l=1,r=2*m;
    int ans=1;
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
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
