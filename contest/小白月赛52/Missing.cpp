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

    int n; cin>>n;
    int maxn=0;
    vector<string> v;
    for(int i=1;i<=n;i++){
        string t; cin>>t;
        int len=t.length();
        int k=0;

        if(s.length()!=len) k=0;
        else{
            for(int j=0;j<s.length()&&j<t.length();j++){
                if(s[j]==t[j]) k++;
            }
        }
        
        if(k==maxn) v.push_back(t);
        else if(k>maxn){
            maxn=max(maxn,k);
            v.clear();
            v.push_back(t);
        }
    }


    sort(_all(v));
    for(auto x:v){
        cout<<x<<endl;
    }
    return;
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
