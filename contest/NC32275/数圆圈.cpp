#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

int cnt[]={1,0,0,0,0,0,1,0,2,1};

int get(int x){
    if(x==0) return 1;
    int res=0;
    while(x){
        int t=x%10;
        x/=10;
        res+=cnt[t];
    }
    return res;
}

void sol(){
    int x,k;
    cin>>x>>k;
    x=abs(x);
    while(x&&k--)
        x=get(x);
    if(k>0) x^=(k&1);
    cout<<x<<'\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) sol();

    return 0;
}
