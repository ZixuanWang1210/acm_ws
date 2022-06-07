#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    s=' '+s;

    int mid=(n+1)/2;
    int ans=1;
    if(n%2==0) ans++;
    for(int i=mid-1;i>=1;i--){
        if(s[i]==s[mid]) ans+=2;
        else break;
    }
    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
