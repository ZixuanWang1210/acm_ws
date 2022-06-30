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

void ccc(int l,int r){
    if(l==r){
        cout<<"! "<<l<<endl;
        return;
    }
    int res=0;
    int mid=(l+r)/2;

    cout<<"? "<<l<<' '<<mid<<endl;
    cout.flush();

    for(int i=l;i<=mid;i++){
        int w; cin>>w;
        if(w>=l&&w<=mid) res++;
    }
    if(res%2==1) ccc(l,mid);
    else ccc(mid+1,r);
}

void sol(){
    int n; cin>>n;
    ccc(1,n);
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
