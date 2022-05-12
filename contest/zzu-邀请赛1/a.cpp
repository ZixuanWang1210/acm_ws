#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int a[10]={0};
    int sum=0;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        sum+=y*6;
        a[x]+=y*6;
    }
    sum/=6;
    for(int i=1;i<=6;i++){
        cout<<a[i]-sum;
        if(i!=6) cout<<' ';
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;