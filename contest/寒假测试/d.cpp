#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e6+10;
int a[maxn],s[maxn];
int n,k;

bool check(int x){
    int idx=lower_bound(a+1,a+1+n,x)-a;
    
}

int main(){
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
    }

    int l=1,r=_max;
    int ans=0;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    return 0;
}
