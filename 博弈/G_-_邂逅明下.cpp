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
    int n,p,q; 
    while(cin>>n>>p>>q){
        if(n%(p+q)&&n%(p+q)<=p) cout<<"LOST"<<endl;
        else cout<<"WIN"<<endl;
    }

    return 0;
}
