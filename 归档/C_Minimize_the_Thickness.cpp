#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),s(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
        cout<<s[i]<<' ';
    }
    cout<<endl;
    int res=inf;
    for(int i=1;i<=n;i++){
        int idx=i;
        int cnt=1;
        while(*lower_bound(s.begin()+i+1,s.end(),s[idx]+s[i])==s[idx]+s[i]){
            cnt++;
            int len=idx;
            idx=lower_bound(s.begin()+i+1,s.end(),s[idx]+s[i])-s.begin();
            len=idx-len+1;
            cout<<len<<" ";
            cnt=max(cnt,len);
            if(idx==n) res=min(res,cnt);
        }
    }
    if(res==inf) cout<<1<<endl;
    else 
    cout<<res<<endl;
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
