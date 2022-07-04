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
    string s1,s2;
    cin>>s1>>s2;
    int l=0;
    int r=0;
    for(int i=0;i<(int)s2.length()&&i<(int)s1.length();i++){
        if(s1[i]==s2[i]) l++;
        else break;
    }
    for(int i=(int)s2.length()-1,j=(int)s1.length()-1;i>=0,j>=0;i--,j--){
        if(s2[i]==s1[j]) r++;
    }
    if(l+r>=(int)s1.length()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
