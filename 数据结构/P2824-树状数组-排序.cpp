#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=1e5+10;
int tr[N],a[N],b[N];
int n,m,idx,q,ans;
struct OP{
    int op,l,r;
} opt[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int b){
    for(; x <= n; x += lowbit(x)) tr[x] += b;
}

int ask(int x){
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += tr[x];
    return ans;
}

bool check(int x){
    for(int i=1;i<=n;i++){
        b[i]=a[i]>=x;
    }
    memset(tr,0,sizeof tr);
    for(int i=1;i<=idx;i++){
        int op=opt[i].op,l=opt[i].l,r=opt[i].r;
        int cnt=ask(r)-ask(l-1);
        for(int j=l,k=1;j<=r;j++,k++){
            if(k<=cnt) b[j]=0;
            else b[j]=1;
        }
    }
    return b[q];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int _max=-1,_min=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        _max=max(_max,a[i]);
        _min=min(_min,a[i]);
    }
    for(int i=1;i<=m;i++){
        int op,l,r; cin>>op>>l>>r;
        opt[++idx]={op,l,r};
    }
    cin>>q;

    int l=_min,r=_max;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    
    return 0;
}
