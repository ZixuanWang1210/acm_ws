#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    int l=0,r=s.length()-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1') l=i;
    }
    for(int i=l;i<s.length();i++){
        if(s[i]=='0') {
            r=i;
            break;
        }
    }
    cout<<r-l+1<<endl;

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
