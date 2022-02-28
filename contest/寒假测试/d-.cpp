#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
#define int long long
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e6;
int a[maxn],s[maxn];
int n,k;

bool check(int x){
    int idx=lower_bound(a+1,a+1+n,x)-a;
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    int _max=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        _max=max(_max,a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        if(a[i]*i>s[i]+k){
            int res=(i-1)*a[i-1]-s[i-1];
            int ans=(k-res)/(i-1)+a[i-1];
            cout<<ans<<endl;
            return 0;
        }
        else if(a[i]*i==s[i]+k){
            cout<<a[i]<<endl;
            return 0;
        }
    }
    cout<<(s[n]+k)/n;

    
    return 0;
}
