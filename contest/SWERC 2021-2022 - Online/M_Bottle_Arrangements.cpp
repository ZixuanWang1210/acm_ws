#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,m;
    cin>>n>>m;
    int a=0,b=0;
    for(int i=1;i<=m;i++){
        int r,w; cin>>r>>w;
        a=max(a,r),b=max(b,w);
    }
    if(a+b>n) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=1;i<=a;i++) cout<<"R";
        for(int i=a+1;i<=n;i++) cout<<"W";
        cout<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
