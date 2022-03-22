#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    int _fi=-0x3f3f3f3f,_se=-0x3f3f3f3f;
    int _max=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        _max=max(_max,v[i]);
    }
    sort(v.begin()+1,v.begin()+1+n);
    v.erase(lower_bound(v.begin()+1,v.begin()+1+n,_max));
    _se=*max_element(v.begin(),v.end());


    cout<<_max+_se<<endl;

}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
