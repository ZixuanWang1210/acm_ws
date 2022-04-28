#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;
#define mod 1000003

void sol(){
    string s; cin>>s;
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]=='.') res=res+"1100";
        else if(s[i]=='>') res=res+"1000";
        else if(s[i]=='<') res=res+"1001";
        else if(s[i]=='+') res=res+"1010";
        else if(s[i]=='-') res=res+"1011";
        else if(s[i]==',') res=res+"1101";
        else if(s[i]=='[') res=res+"1110";
        else if(s[i]==']') res=res+"1111";
    }
    // cout<<res<<endl;
    int ans=0,base=1;

    for(int i=res.length()-1;i>=0;i--){
        if(res[i]=='1'){
            ans=(ans+base)%mod;
        }
        base=2*base%mod;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
