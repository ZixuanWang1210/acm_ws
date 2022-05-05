#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.begin()+1+n);
    for(int i=1;i<=n;i++){
        if(i!=n) sum+=v[i];
    }
    if(sum<v[n]-1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

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
