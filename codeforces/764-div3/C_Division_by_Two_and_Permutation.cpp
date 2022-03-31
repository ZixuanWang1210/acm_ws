#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

// void sol(){
//     int n; cin>>n;
//     vector<int> v(2*n);
//     // set<int> st;
//     // unordered_map<int,int> st;
//     vector<bool> st(100);
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//     }
//     sort(v.begin()+1,v.begin()+1+n);
//     int base=1;
//     for(int i=1;i<=n;i++){
//         base/=2;
//         if(base==0) base=1;
//         while(v[i]>n){
//             base*=2;
//             v[i]/=base;
//         }
//         if(st[v[i]]==0) st[v[i]]=1;
//         else{
//             while(st[v[i]]==1){
//                 if(v[i]==1){
//                     cout<<"NO"<<endl;
//                     return;
//                 }
//                 v[i]>>=1;
//             }
//             st[v[i]]=1;            
//         }
//     }
//     cout<<"YES"<<endl;

// }

void sol(){
    int n; cin>>n;
    bool st[100]={0};
    int v[100];
    
    for(int i=1;i<=n;i++){
        cin>>v[i];
        while((v[i]>n||st[v[i]])&&v[i]) v[i]>>=1;
        st[v[i]]=1;
    }
    bool falg=0;
    for(int i=1;i<=n;i++) if(!st[i]) falg=1;
    if(falg)    cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

// void sol(){
//     int n; cin>>n;
//     vector<int> v(2*n);
//     // set<int> st;
//     unordered_map<int,int> st;
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         int t;
//         // if(v[i]<=n){
//         //     t=v[i];
//         // }
//         // else{
//         //     t=v[i]/n;
//         //     t=t*n;
//         // }
//         t=v[i]%(n);
//             cout<<t<<' ';
//         // v[i]=t;
//         // if(st[v[i]]==0) st[v[i]]=1;
//         // else{
//         //     while(st[v[i]]==1){
//         //         if(v[i]==1){
//         //             cout<<"NO"<<endl;
//         //             return;
//         //         }
//         //         v[i]/=2;
//         //     }
//         //     st[v[i]]=1;            
//         // }
//     }
//     cout<<"YES"<<endl;

// }
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
