#include <bits/stdc++.h>
#define int long long 
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v1(2*n),v2(2*n);
    for(int i=1;i<=n;i++){
        cin>>v1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v2[i];
    }
    for(int i=1;i<=n;i++){
        if(v2[i]>=v1[i]){
            swap(v1[i],v2[i]);
        }
    }
    int a=*max_element(v1.begin()+1,v1.begin()+1+n);
    int b=*max_element(v2.begin()+1,v2.begin()+1+n);
    cout<<a*b<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
