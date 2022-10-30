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


signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    int n;
    while(cin>>n,n){
        vector<int> v(n);
        bool ok=true;
        map<int,int> mp;
        for(int i=0;i<n;i++) cin>>v[i],mp[v[i]]++;
        for(auto x:mp){
            if(x.second&1) ok=false;
        }
        // for(int i=1;i<n;i++) if(v[i]!=v[i-1]) ok=false;

        if(ok&&n%2==0) cout<<"Lose"<<endl;
        else cout<<"Win"<<endl;

    }
    return 0;
}
