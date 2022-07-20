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
    int n,q; cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    int now=0;
    int res=0;
    // vector<int> ans;
    string ans;
    for(int i=n;i>=1;i--){
        if(now>=v[i]) ans='1'+ans;
        else{
            if(now+1>q) ans='0'+ans;
            else ans='1'+ans,now++;
        }
        // if(now+1==v[i]) res++,now++,ans=ans+'1';
        // else if(now==v[i]) res++,ans=ans+'1';
        // else ans=ans+'0';
        // if(now>q) now=q;
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
