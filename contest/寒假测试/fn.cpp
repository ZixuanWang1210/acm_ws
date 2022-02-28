#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long 
using namespace std;

int t;
int n;
const int maxn=20000*2;
int a[maxn],s[maxn];
bool tg[maxn]={false};

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        string ss; cin>>ss;
        int x; cin>>x;

        if(ss=="LOST") a[i]=-x;
        else a[i]=x;
    }
    int _max=-0x3f3f3f3f,idx=0;
    for(int i=n;i>=1;i--){
        s[i]=s[i+1]+a[i];
        if(s[i]>_max){
            _max=max(_max,s[i]);
            idx=i;
        }
    }

    int _min=0;
    int ans=0;
    for(int i=n;i>=idx;i--){
        ans+=a[i];
        _min=min(_min,a[i]);
    }
    cout<<ans-_min<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        sol();
    }
    
    return 0;
}
