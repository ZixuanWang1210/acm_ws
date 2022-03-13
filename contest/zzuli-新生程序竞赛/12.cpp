#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P=1000000007;
// int n;

void sol(){
    int n; cin>>n;
    int res=0;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        if(t%2) res++;
    }
    if(res%2) cout<<1<<endl;
    else cout<<0<<endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}