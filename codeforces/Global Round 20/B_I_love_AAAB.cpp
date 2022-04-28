#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

// void sol(){
//     string s; 
//     cin>>s;
//     int len=s.length();
//     bool have_a=false,have_b=false;
//     if(len==1){
//         cout<<"NO"<<endl;
//         return;
//     }
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='A') have_a=true;
//         else have_b=true;
//         if(s[i]=='B'&&s[i+1]=='B'){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     if(have_a==false||have_b==false) {
//         cout<<"NO"<<endl;
//         return;
//     }
//     cout<<"YES"<<endl;
//     return;

// }
// void sol(){
//     string s; cin>>s;
//     int cnt=0;
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='A'){
//             cnt++;
//         }
//         else{
//             if(cnt==0){
//                 cout<<"NO"<<endl;
//                 return;
//             }
//             cnt=0;
//         }
//     }
//     if(cnt) cout<<"NO"<<endl;
//     else cout<<"YES"<<endl;
// }
void sol(){
    string s; cin>>s;
    int sum=0;
    int len=s.length()-1;
    if(s[len]!='B'||len==0){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='A') sum++;
        else sum--;
        if(sum<0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
