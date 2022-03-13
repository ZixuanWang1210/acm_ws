#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P=1000000007;
// int n;

void sol(){
    // cout<<0%2<<endl;
    int n; cin>>n;
    int res=0;
    int odd=0,even=0;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        if(t%2) odd++;
        else even++;
    }
    // cout<<odd<<' '<<even<<endl;
    // cout<<odd*even<<endl;
    if((odd*even)%2) cout<<1<<endl;
    else cout<<0<<endl;
}
// void sol(){
//     int n; cin>>n;
//     vector<int> v(2*n);
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         int t; cin>>t;
//         if(t%2) t=1;
//         else t=0;
//         v[i]=t;
//     }
//     for(int i=2;i<=n;i++){
//         // cout<<v[i]<<' ';
//         v[i]=v[i-1]^v[i];
//     }
//     cout<<v[n];
// }

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}