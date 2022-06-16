#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    int cnt[20]={0};
    int sum=0;
    for(auto x:s){
        int xx=x-'0';
        if(xx) cnt[xx%3]++;
        sum+=xx;
    }

    if(!cnt[sum%3]) {
        cout<<"yukari";
        return;
    }
    cnt[sum%3]--;
    if(cnt[1]==cnt[2]&&cnt[0]){
        cout<<"kou";
    }
    else cout<<"yukari";
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
