#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,r,b; 
    cin>>n>>r>>b;
    int cnt=min(r,b); 
    r-=b; 
    if(r){
        cout<<'R';
        r--;
    }
    int tt=ceil((double)r/(cnt+1)); 
    while(cnt--){
        for(int i=1;i<=tt;i++){
            if(r==0) break;
            r--;
            cout<<"R";
        }
        cout<<"BR";
    }
    for(int i=1;i<=tt;i++){
        if(r==0) break;
        r--;
        cout<<"R";
    }
    // cout<<endl;

    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
