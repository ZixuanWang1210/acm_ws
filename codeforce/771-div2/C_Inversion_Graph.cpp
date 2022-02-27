#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    long long sum=0,cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
        cnt+=i;
        if(cnt==sum) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
