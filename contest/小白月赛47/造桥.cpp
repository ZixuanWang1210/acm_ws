#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    int mp[30]={0};
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        int len=s.length()-1;
        mp[s[len]-'a']=max(mp[s[len]-'a'],mp[s[0]-'a']+len+1);
    }
    int ans=-0x3f3f3f3f;
    for(int i=0;i<26;i++){
        ans=max(ans,mp[i]);
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) sol();

    return 0;
}
