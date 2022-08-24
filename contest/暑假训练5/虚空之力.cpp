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
    int cntk=0,cnts=0,cnti=0,cntn=0,cntg=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='k') cntk++;
        else if(s[i]=='i') cnti++;
        else if(s[i]=='n') cntn++;
        else if(s[i]=='g') cntg++;
    }
    int t=min({cnti,cntn,cntg});
    if(2*cntk<=t){
        cout<<2*cntk<<endl;
        return;
    }
    else{
        cout<<t<<endl;
        return;
    }
    // cout<<min({cntk,cnti,cntn,cntg})<<endl;
    

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
