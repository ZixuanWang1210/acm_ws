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

const int maxn=1e5+10;
int L[maxn],R[maxn],a[maxn];
int n;

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    R[1]=1;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]) R[i]=R[i-1]+1;
        else R[i]=1;
    }
    L[n]=1;
    for(int i=n;i>=1;i--){
        if(a[i]<a[i+1]) L[i]=L[i+1]+1;
        else L[i]=1;
    }

    int ans=1;
    for(int i=1;i<=n;i++){
        if(a[i+1]-1>a[i-1]){
            ans=max(ans,R[i-1]+L[i+1]+1);
        }
        else ans=max(ans,max(R[i-1],L[i+1])+1);
    }
    cout<<ans<<endl;
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
