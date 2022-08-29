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

bool judge(int x){
    if(x<2) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}

void sol(){
    int n; cin>>n;
    if(n==1) {cout<<7<<endl;return;}
    int l=n,r=9*n;
    int x=0;
    for(int i=l;i<=r;i++){
        if(judge(i)){x=i;break;}
    }
    // cout<<x<<endl;
    int base=x/n;
    int res=x%n;
    // debug(res);
    for(int i=1;i<=res;i++) cout<<base+1;
    for(int i=res+1;i<=n;i++) cout<<base;
    cout<<endl;

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


// 22111111111
// 222211111111