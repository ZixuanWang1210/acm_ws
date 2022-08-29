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
    int H; cin>>H;
    int res=H;
    int cnt[20];
    for(int i=1;i<=10;i++) cin>>cnt[i];

    for(int i=10;i>=1;i--){
        if(cnt[i]*i<=H) H-=cnt[i]*i;
        else{
            int t=H/i;
            cnt[i]-=t;
            H-=t*i;
        }
    }
    cout<<res-H<<endl;
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
