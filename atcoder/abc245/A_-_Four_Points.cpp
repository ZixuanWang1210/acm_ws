#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

map<int,int> mp1,mp2;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=1;i<=3;i++){
        int a,b; cin>>a>>b;
        mp1[a]++,mp2[b]++;
    }
    for(auto x:mp1){
        if(x.second==1) cout<<x.first<<' ';
    }
    for(auto x:mp2){
        if(x.second==1) cout<<x.first<<' ';
    }
    

    return 0;
}
