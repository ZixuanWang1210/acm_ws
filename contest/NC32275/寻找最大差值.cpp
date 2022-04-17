#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n),mx(n),mn(n),res(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(is_sorted(v.begin(),v.begin()+n,greater<int>())){
        cout<<-1<<endl;
        return;
    }
    int _max=-0x3f3f3f3f;
    for(int i=n-1;i>=0;i--){
        if(_max<v[i]){
            _max=v[i];
        }
        mx[i]=_max;
    }
    int _min=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        if(v[i]<_min){
            _min=v[i];
        }
        mn[i]=_min;
        res[i]=mx[i]-mn[i];
    }
    cout<<*max_element(res.begin(),res.end())<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) sol();

    return 0;
}
