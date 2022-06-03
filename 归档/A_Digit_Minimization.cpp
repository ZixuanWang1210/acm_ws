#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    int idx=0;
    int res=0x3f3f3f3f;
    for(int i=0;i<s.length();i++){
        int x=s[i]-'0';
        if(x<res) res=x,idx=i;
    }

    int n=s.length();
    if(n<=2){
        cout<<s[1]<<endl;
    }
    else cout<<res<<endl;

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
