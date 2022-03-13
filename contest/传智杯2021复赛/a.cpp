#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;
string s;
int ans;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    string s1="chuanzhi";

    while(s.find(s1)!=s.npos){
        auto tt=s.find(s1);
        s.erase(tt,s1.size());
        ans++;
    }
    
    cout<<ans;
    return 0;
}
