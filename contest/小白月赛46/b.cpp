#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;


vector<int> v;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    bool bz=true;
    
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x==0){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            v.push_back(x);
        }
    }

    int cmp=v[0];
    bool bz2=true;
    bool bz3=true;
    for(int i=1;i<v.size();i++){
        if(abs(v[i])!=abs(cmp)) bz2=false;
    }
    for(int i=1;i<v.size();i++){
        if(v[i]!=cmp) bz3=false;
    }
    if(bz2&&!bz3)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
