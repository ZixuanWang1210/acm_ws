#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

// void sol(){
//     int a,b,c,x,y; 
//     cin>>a>>b>>c>>x>>y;

//     int t=max(x-a,0ll);

//     if(b+c-t>=y) cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;
// }

void sol(){
    int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    if(x>a) c-=(x-a);
    if(y>b) c-=(y-b); 
    if(c>=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
