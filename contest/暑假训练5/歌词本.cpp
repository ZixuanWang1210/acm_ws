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
    int op; 
    map<string,int> mp;
    while(cin>>op){
        string s; cin>>s;
        if(op==1){
            mp[s]++;
        }
        else if(op==2){
            if(mp[s]==0){
                cout<<"Baka Miku, string \""<< s <<"\" doesn't exsit."<<endl;
            }
            else{
                mp[s]--;
                cout<<"String \""<<s<<"\" has been deleted once.";
            }
        }
        else if(op==3){
            cout<<"----------"<<endl<<"Miku's Lyrics Book:"<<endl;
            for(auto x:mp){
                cout<<x.first<<endl;
            }
            cout<<"----------"<<endl;
        }
        else{
            if(mp[s]){
                cout<<"String \""<< s <<"\" is exsit, there is (are) "<<mp[s]<<" in the book."<<endl;;
            }
            else{
                // mp[s]--;
                cout<<"String \""<<s<<"\" doesn't exsit.";
            }
        }
    }

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
