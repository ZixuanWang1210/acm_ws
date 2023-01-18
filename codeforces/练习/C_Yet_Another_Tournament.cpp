#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    vector<int> a(n+1),b(n+1);
    int cnt=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(all(a));
    int les;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum<=m) cnt++,les=m-sum;
    }

    if(cnt==0){
        cout<<n+1<<endl;
        return;
    }
    else if(cnt==n){
        cout<<1<<endl;
        return;
    }
    else{
        int now=cnt;
        int ok=1;
        // cout<<les<<' ' <<now<<endl;
        if(b[now+1]<=les+a[now]){
            ok=0;
        }
        cout<<n-now+ok<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
