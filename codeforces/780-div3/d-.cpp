#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// #define int long long
#define pii pair<int,pair<int,int>>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

// void sol(){
//     int n; cin>>n;
//     vector<int> v(2*n),s(2*n),pre(2*n);
//     int sum=1;
//     int bg=1;
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         if(v[i]==0){
//             sum=1;
//             bg=i+1;
//         }
//         else{
//             s[i]=sum*v[i];
//             sum*=v[i];
//             pre[i]=bg;
//         } 
//     }
//     int bz=*max_element(v.begin()+1,v.begin()+1+n);
//     cout<<bz<<endl;
//     if(bz<0){
//         cout<<n<<' '<<0<<endl;
//         return ;
//     }
//     else{
//         for(int i=1;i<=n;i++){
//             if(s[i]==bz){
//                 cout<<pre[i]<<' '<<n-i<<endl;
//                 return ;
//             }
//         }
//     }
// }

void sol(){
    int n; cin>>n;
    vector<int> v(2*n),s(2*n);
    vector<pii> ss;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int cntfu=0,bg=0,sum=1;
    for(int i=0;i<n;i++){
        if(v[i]!=0){
            if(v[i]<0) cntfu++;
            sum*=v[i];
        }
        if(v[i]==0){
            if(cntfu%2==0)
                ss.push_back({sum,{bg,i}});
            else{
                int ttt=sum/v[bg];
                ss.push_back({ttt,{bg+1,i-1}});
                ttt=sum/v[i-1];
                ss.push_back({ttt,{bg,i-2}});
            }
        }
    }
    if(cntfu%2==0)
        ss.push_back({sum,{bg,n-1}});
    else{
        ss.push_back({sum/v[bg],{bg+1,n-1-1}});
        ss.push_back({sum/v[bg-1],{bg,n-1-2}});
    }
    sort(ss.begin(),ss.end());
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
