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
    string s; cin>>s;
    if(s.length()==1){
        cout<<s<<endl;
        return;
    }
    bool ok=true;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!='9') {ok=false;break;}
    }
    if(ok){
        cout<<s<<endl;
    }
    else{
        int cnt=s.length()-1;
        for(int i=1;i<=cnt;i++) cout<<9;
    }

    // // if(s[0]=='9') cout<<s<<endl;
    // // else{
    // // }

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
