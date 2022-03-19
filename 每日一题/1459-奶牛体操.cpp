#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1100;
int up[maxn],down[maxn];
int k,n;
int ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>n;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            up[x]=min(up[x],j);
            down[x]=max(down[x],j);
        }
    }
    for(int i=1;i<=n;i++){
        int dw=down[i];
        for(int j=1;i<=n;j++){
            if(i==j) continue;
            if(down[i]>=up[j]) ans++;
        }
    }
    cout<<ans;
    

    return 0;
}
