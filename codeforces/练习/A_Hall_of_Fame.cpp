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
    string s; cin>>s;
    bool ok=true;
    for(int i=1;i<s.length();i++){
        if(s[i]!=s[i-1]) ok=false;
    } 

    if(ok){
        cout<<-1<<endl;
        return;
    }

    for(int i=1;i<=n;i++){
        if(s[i]=='L'&&s[i-1]=='R'){
            cout<<0<<endl;
            return;
        }
        else if(s[i]=='R'&&s[i-1]=='L'){
            cout<<i<<endl;
            return;
        }
    }
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
