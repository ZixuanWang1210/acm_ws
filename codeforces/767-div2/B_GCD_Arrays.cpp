#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

// void sol(){
//     int l,r,k; cin>>l>>r>>k;
//     int cnt=r-l+1;
//     int ji,ou,need;
//     if(l==r&&k==0){
//         if(l==1){
//             cout<<"NO"<<endl;
//             return;
//         }
//         cout<<"YES"<<endl;
//         return;
//     }
//     if(l&1&&cnt&1){
//         ji=cnt/2+1;
//         ou=cnt/2;
//         need=ou+1;
//     }
//     else if(l&1==0&&cnt&1){
//         ji=cnt/2;
//         ou=cnt/2+1;
//         need=ji;
//     }
//     else if(cnt&1==0){
//         ji=ou=cnt/2;
//         need=ji;
//     }
//     if(need<=k){
//         cout<<"YES"<<endl;
//         return;
//     }
//     else{
//         cout<<"NO"<<endl;
//         return;
//     }
// }


void sol(){
    int l,r,k; cin>>l>>r>>k;
    int cnt=r-l+1;
    int need=0;
    if(l==r){
        if(l==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        return;
    }
    if(cnt&1){
        if(l&1) need=cnt/2+1;
        else need=cnt/2; 
    }
    else{
        need=cnt/2;
    }
    if(need<=k){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
