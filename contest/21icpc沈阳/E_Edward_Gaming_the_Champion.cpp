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
    int cnt=0;
    for(int i=0;i-5<(int)s.length();i++){
        if(s[i]=='e'&&s[i+1]=='d'&&s[i+2]=='g'&&s[i+3]=='n'&&s[i+4]=='b') cnt++;
    }
    cout<<cnt<<endl;

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
