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
    int n; cin>>n;
    string s; cin>>s;
    s+='#';
    int res=1;
    int cnt=1;
    int cnt1=0,cnt0=0;
    for(int i=0;i<=n-1;i++){
        if(s[i]=='0') cnt0++;
        else cnt1++;
        if(i==0) continue;

        if(s[i]==s[i-1]) cnt++;
        else{
            res=max(res,cnt);
            cnt=1;
        }
    }
    res=max(res,cnt);
    // cout<<res<<' '<<cnt1<<' '<<cnt0<<endl;
    cout<<max(res*res,cnt1*cnt0)<<endl;

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
