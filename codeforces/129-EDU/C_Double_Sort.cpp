#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,pair<int,int>>
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v1(n+1),v2(n+1);
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        cin>>v1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v2[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v1[i]<v1[j]||(v1[i]==v1[j]&&v2[i]<v2[j])){
                swap(v1[i],v1[j]);
                swap(v2[i],v2[j]);
                ans.push_back({i,j});
            }
        }
    }

    if(!is_sorted(v2.begin()+1,v2.begin()+1+n)){
        cout<<-1<<endl;
        return;
    }
    
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.first<< ' '<<x.second<<endl;
    }


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
