#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=2e5+10;
int a[N],b[N];
int n;

bool check(int x){
    for(int i=1;i<(n<<1);i++) b[i]=a[i]>x;
    for(int i=0;i<n-1;i++){
        if(b[n+i]==b[n+i+1]) return b[n+i];
        if(b[n-i]==b[n-i-1]) return b[n-i];
    }
    return b[1];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int _min=0x3f3f3f3f,_max=-1;
    for(int i=1;i<(n<<1);i++){
        cin>>a[i];
        _min=min(_min,a[i]);
        _max=max(_max,a[i]);
    }

    int l=_min,r=_max,ans=-0x3f3f3f3f;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
        
    }
    
    cout<<ans+1;
    return 0;
}
