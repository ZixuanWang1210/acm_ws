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
const int maxn=2e4+10;
string s[maxn];
int idx=0;
void sol(){
    while(getline(cin,s[++idx])){
    }
    int len1=to_string(idx).length();
    // cout<<len1<<endl;
    for(int i=1;i<=idx;i++){
        int len2=to_string(i).length();
        // cout<<len2<<endl;
        for(int j=len2;j<len1;j++){
            cout<<" ";
        }
        cout<<i<<' ';
        cout<<s[i]<<endl;
    }
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
