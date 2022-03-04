#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol(){
    unordered_set<int> s;
    map<int,int> mp;
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int tt; cin>>tt;
        // s.insert(tt);
        mp[tt]++;
    }
    int cnt=mp.size();
    for(int i=1;i<=n;i++){
        if(i<=mp.size()){
            cout<<cnt<<' ';
        }
        else{
            cout<<i<<' ';
        }
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;cin>>t;
    while(t--){
        sol();
    }
    return 0;
}