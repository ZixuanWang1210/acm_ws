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

void sol(){
    _sleep(100000000);
    int n; cin>>n;
    string s; cin>>s;
    if(s[0]=='0'||s[n-1]=='0'){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> c1,c2;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            c1.push_back(i);
        }
        else{
            c2.push_back(i);
        }
    }
    if(c2.size()&1){
        cout<<"NO"<<endl;
        return;
    }
    // vector<char> v1(n+1),v2(n+1);
    string s1,s2;
    int bz=1;
    bool bz1=1;
    for(int i=1;i<n-1;i++){
        if(s[i]=='1'){
            if(bz) s1+='(',s2+='(',bz=0;
            else s1+=')',s2+=')',bz=1;
        }
        else{
            if(bz1) s1+=')',s2+='(',bz1=0;
            else s1+='(',s2+=')',bz1=1; 
        }
    }
    s1='('+s1+')';
    s2='('+s2+')';
    // for(int i=0;i<c1.size();i++){
    //     if(i&1) v1[c1[i]]=')',v2[c1[i]]=')';
    //     else v1[c1[i]]='(',v2[c1[i]]='(';
    // }

    // for(int i=0;i<c2.size();i++){
    //     if(i&1){
    //         v1[c2[i]]='(',v2[c2[i]]=')';
    //     }
    //     else{
    //         v1[c2[i]]=')',v2[c2[i]]='(';
    //     }
    // }
    cout<<"YES"<<endl;
    cout<<s1<<endl<<s2<<endl;
    // for(int i=0;i<n;i++){

    //     cout<<v1[i];
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<v2[i];
    // }
    // cout<<endl;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
