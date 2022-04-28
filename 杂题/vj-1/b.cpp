#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> ans;
    vector<int> v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    double avg=(double)sum/n;
    for(int i=1;i<=n;i++){
        if(avg==(double)(sum-v[i])/(n-1)) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<' ';


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
