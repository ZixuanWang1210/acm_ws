#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n,m;
const int maxn=1e4;
map<int,int> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        int t; cin>>t;
        mp[t]++;
    }
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        if(mp[t]==0){
            cout<<"No"<<endl;
            return 0;
        }
        mp[t]--;
    }
    cout<<"Yes"<<endl;
    

    return 0;
}
