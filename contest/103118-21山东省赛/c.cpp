#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
const int maxn=1e5+10;
#define int long long 
using namespace std;
vector<pair<int,int>> v;

void sol(){
    int k; cin>>k;
    int idx=1;
    while(k){
        if(k==2) break;
        else if(k==3){
            v.push_back({idx,idx+1});
            idx++;
            break;
        }
        if(k&1){
            v.push_back({idx,idx+1});
            v.push_back({idx,idx+2});
            idx+=2;
            k=(k-1)/2;
            continue;
        }
        else{
            v.push_back({idx,idx+1});
            idx++;
            k--;
        }
    }

    cout<<v.size()+1<<endl;
    for(auto x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    while(_--){
        sol();
    }

    return 0;
}
