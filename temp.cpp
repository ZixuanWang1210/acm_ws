#include<bits/stdc++.h>
#define int long long 
using namespace std;

string s;

void sol(){
    int t,k; cin>>t>>k;
    int change=0;
    while(t--){
        if(k&1) change++;
        else change+=2;

        k=(k+1)/2;
    }
    char base=s[k];
    change%=3;
    base+=change;
    if(base=='E') base='B';
    if(base=='D') base='A';
    cout<<base<<endl;
}

signed main(){
    // cin>>s;
    // s='0'+s;
    // int _; cin>>_;
    // while(_--){
    //     sol();
    // }

    return 0;
}