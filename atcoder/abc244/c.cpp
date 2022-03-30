#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;
 
 
 
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin>>n>>k;
    vector<int> v,v2(2*n),v1(2*n);
    for(int i=1;i<=n;i++){
        cin>>v1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v2[i];
    }
    v.push_back(v1[1]);
    v.push_back(v2[1]);
    for(int i=2;i<=n;i++){
        int siz=v.size();
        vector<int> t;
        for(auto x:v){
            if(abs(x-v1[i])<=k) t.push_back(v1[i]);
            if(abs(x-v2[i])<=k) t.push_back(v2[i]);
        }
        // v=t;
        v.erase(v.begin(),v.begin()+siz-1);

        if(v.size()==0){
            cout<<"No"<<endl;
            return 0;
        }
        
    }
    
    cout<<"Yes"<<endl;
    return 0;
}