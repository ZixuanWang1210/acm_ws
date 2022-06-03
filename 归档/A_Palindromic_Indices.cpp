#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    s=' '+s;
    int ans=0;
    int mid=n/2;
    if(n%2==1){
        mid+=1;
    }
    
    for(int i=mid;i<=n;i++){
        if(s[i]==s[mid]) ans++;
        else break;
    }
    for(int i=mid-1;i>=1;i--){
        if(s[i]==s[mid]) ans++;
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
