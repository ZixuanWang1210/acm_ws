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
    vector<int> v(n+1),s(n+2);
    vector<int> vec;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
        if(!v[i]) vec.push_back(i);
    }
    for(int i=0;i<vec.size();i++){
        int nxt;
        if(i<vec.size()-1) nxt=vec[i+1];
        else nxt=n+1;
        int mx=0;
        map<int,int> mp;
        for(int j=vec[i];j<nxt;j++){
            mp[s[j]]++;
            if(mp[s[j]]>mx) mx=mp[s[j]];
        }
        ans+=mx;
    }
    if(vec.size()){
        for(int i=1;i<=vec[0]-1;i++) if(s[i]==0) ans++;
    }
    else{
        for(int i=1;i<=n;i++) if(s[i]==0) ans++;
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
