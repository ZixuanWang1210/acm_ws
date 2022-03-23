#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int x,y; cin>>x>>y;
    if(x==0&&y==0){
        cout<<0<<endl;
        return;
    }
    int res=sqrt(x*x+y*y);
    if(res*res==x*x+y*y) cout<<1<<endl;
    else cout<<2<<endl;


    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
