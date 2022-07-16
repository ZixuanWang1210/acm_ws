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
    string s; cin>>s;
    int len=s.length();
    s=' '+s;
    char x=s[1];
    int idx=-1;
    for(int i=1;i<=len;i++){
        if(s[i]!=x){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        cout<<len-1<<endl;
        return;
    }
    cout<<len+(len-idx+1)<<endl;
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
