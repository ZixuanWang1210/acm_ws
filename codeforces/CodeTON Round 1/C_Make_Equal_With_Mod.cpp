#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    bool bz=false;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]==1) bz=true;
    }
    sort(v.begin()+1,v.begin()+1+n);
    if(bz){
        for(int i=1;i<=n-1;i++){
            if(abs(v[i+1]-v[i])==1) bz=false;
        }
        if(bz){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
