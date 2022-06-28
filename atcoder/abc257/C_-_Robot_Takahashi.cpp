#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

// void sol(){
//     int n; cin>>n;
//     string s; cin>>s;
//     vector<int> v(n+1);
//     vector<int> v1,v2;
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         if(s[i-1]=='1') v1.push_back(v[i]);
//         else v2.push_back(v[i]);
//     }


//     sort(_all(v1)),sort(_all(v2));

//     // if(v1.size()>v2.size()){
//     //     int xx=v1[0];
//     //     cout<<xx<<endl;
//     //     int ans=0;
//     //     for(auto x:v2){
//     //         if(xx>x) ans++;
//     //     }
//     //     cout<<ans+v1.size()<<endl;
//     //     return;
//     // }

//     // else if(v1.size()<v2.size()){
//     //     int xx=v2.back();
//     //     int ans=0;
//     //     for(auto x:v1){
//     //         if(xx<x) ans++;
//     //     }
//     //     cout<<ans+v2.size()<<endl;
//     //     return;
//     // }

//     // else{
    
//         // int xx=v1[0];
//         // int ans=0;
//         // for(auto x:v2){
//         //     if(xx>x) ans++;
//         // }
//         // int ans1=ans+v1.size();

//         // xx=v2.back();
//         // ans=0;
//         // for(auto x:v1){
//         //     if(xx<x) ans++;
//         // }
//         // int ans2=ans+v2.size();
//         // cout<<max(ans1,ans2)<<endl;
//     // }

//     // if(v1.size()==0){
//     //     cout<<v2.size()<<endl;
//     //     return;
//     // }
//     // if(v2.size()==0){
//     //     cout<<v1.size()<<endl;
//     //     return;
//     // }

//     // int m1=v1[0],m2=v2.back();
//     // int ans1=v1.size(),ans2=v2.size();
//     // for(auto x:v2){
//     //     if(x<m1) ans1++;
//     // }

//     // for(auto x:v1){
//     //     if(x>m2) ans2++;
//     // }
//     // cout<<max(ans1,ans2)<<endl;
// }

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    vector<pii> v;
    v.push_back({0,0});
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        v.push_back({x,s[i-1]-'0'});
    }

    sort(all(v));

    vector<int> v0(n+1),v1(n+2);
    for(int i=1;i<=n;i++){
        v0[i]=(v[i].second==0)+v0[i-1];
        cout<<v0[i]<<' ';
    }
    for(int i=n;i>=1;i--){
        v1[i]+=(v[i].second==1)+v1[i+1];
        cout<<v1[i]<<' ';
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,v0[i]+v1[i-1]);
    }
    for(int i=1;i<=n-1;i++){
        ans=max(ans,v0[i]+v1[i+1]);
    }
    cout<<ans<<endl;

}



signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
