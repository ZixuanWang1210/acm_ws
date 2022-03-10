#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2e5+10;
int a[maxn];
int n,k;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int idx=0;
    int ans=0;
    while(k--){
        idx=ans;
        idx=idx%n;
        idx=a[idx];
        ans+=idx;
    }
    cout<<ans<<endl;
    

    return 0;
}
