#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(30);
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        v[x+10]++;
    }
    long long sum=0;
    for(int i=0;i<10;i++){
        sum+=v[i]*v[20-i];
    }
    sum+=v[10]*(v[10]-1)/2;
    cout<<sum<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
