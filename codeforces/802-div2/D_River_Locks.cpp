#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int tt=0;
    for(int i=1;i<=n;i++){  
        sum+=v[i];
        tt=max(tt,(sum+i-1)/i);
    }   
    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        if(x<tt) cout<<-1<<endl;
        else cout<<(sum+x-1)/x<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
