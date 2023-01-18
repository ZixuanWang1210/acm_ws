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
    int n,m; cin>>n>>m;
    int cnt1=m,cnt0=n-m;
    string s;
    for(int i=1;i<=n;i++){
        if(cnt1){
            if(cnt0>=2) s+="100",cnt1--,cnt0-=2,i+=2;
            else if(cnt0==1) s+="10",cnt1--,cnt0--,i++;
            else s+='1',cnt1--;
        }
        else{
            if(cnt0) s+='0',cnt0--;
        }
    }
    // cout<<s<<endl;
    int res=0;
    for(int i=0;i<s.length()-2;i++){
        int c1=0,c0=0;
        for(int j=0;j<3;j++){
            if(s[i+j]=='1') c1++;
            else c0++;
        }
        if(c1>c0) res++;
    }
    cout<<res<<endl;
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
