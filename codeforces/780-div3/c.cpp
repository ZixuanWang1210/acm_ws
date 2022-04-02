#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
using namespace std;

// void sol(){
//     string s; cin>>s;
//     int cnt=0;
//     int mp[30];
//     for(int i=0;i<26;i++){
//         mp[i]=-1;
//     }
//     int res=0;
//     for(int i=0;i<s.length();i++){
//         if(s[i]==s[i+1]){
//             for(int i=0;i<26;i++){
//                 if(mp[i]!=-1) res++;
//             }
//             for(int i=0;i<26;i++){
//                 mp[i]=-1;
//             }
//             cnt++;
//             i++;
//         }
//         else{
//             int ver=s[i]-'a';
//             if(mp[ver]!=-1){
//                 res+=(i-mp[ver]-1);
//                 for(int i=0;i<26;i++){
//                     mp[i]=-1;
//                 }
//             }
//             else mp[ver]=i;
//         }
//     }
//     for(int i=0;i<26;i++){
//         if(mp[i]!=-1) res++;
//     }
//     if((s.length()-res)%2==1) res++;
//     cout<<res<<endl;
// }

void sol(){
    string s;
    cin>>s;
    int mp[30]={0};
    int res=0;
    for(int i=s.length()-1;i>=0;i--){
        int ver=s[i]-'a';
        if(mp[ver]!=0){
            // res+=(mp[ver]-i)
            res+=2;
            memset(mp,0,sizeof mp);
        }
        else{
            mp[ver]=1;
        }
    }
    cout<<s.length()-res<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
