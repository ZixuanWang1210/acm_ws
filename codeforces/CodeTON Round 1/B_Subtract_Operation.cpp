#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long
using namespace std;


// void sol(){
//     int n,k; cin>>n>>k;
//     vector<int> v(2*n);
//     int sum=0;
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         sum+=v[i];
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(v[i]-v[j]==k){
//                 cout<<"YES"<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<"NO"<<endl;
//     return;
// }

// void sol(){
//     int n,k; cin>>n>>k;
//     vector<int> v(2*n);
//     // int sum=0;
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         // sum+=v[i];
//     }
//     sort(v.begin()+1,v.begin()+1+n);

//     for(int i=1;i<=n;i++){
//         int res=v[i]+k;
//         int ff=*lower_bound(v.begin()+1,v.begin()+1+n,res);
//         if(ff==res){
//             cout<<"YES"<<endl;
//             return;
//         }
//     }
//     cout<<"NO"<<endl;
//     return;

// }

void sol(){
    int n,k; cin>>n>>k;
    set<int> s;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        s.insert(t);
    }
    for(auto x:s){
        int res=x+k;
        if(s.count(res)>=1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    
    return 0;
}
