#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    map<int,string> mp;
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        int t;
        cin>>s>>t;
        mp[t]=s;
    }
    for(auto x:mp){
        cout<<x.second;
        if(x.second=="."||x.second=="!") cout<<endl;
        else cout<<" ";
    }
    

    return 0;
}
