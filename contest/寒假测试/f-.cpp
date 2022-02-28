#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long 
using namespace std;

int t;
int n;
const int maxn=10;
int a[maxn],s[maxn];
bool tg[maxn]={false};

void sol(){
    int n; cin>>n;
    int _min=0;
    memset(tg,0,sizeof tg);
    memset(a,0,sizeof a);
    memset(s,0,sizeof s);
    bool falg=true,bz=true;
    for(int i=1;i<=n;i++){
        string ss; cin>>ss;
        int x; cin>>x;
        if(falg&&ss=="LOST"){
            falg=false;
            continue;
        }
        falg=false;
        if(ss=="LOST") a[i]=-x;
        else a[i]=x;
        s[i]=s[i-1]+a[i];
        if(s[i]<=0) bz=false;
        _min=min(_min,a[i]);
        
    }
    if(bz){
        cout<<s[n]-_min<<endl;
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+a[i];
            if(s[i]<=0) tg[i]=true,s[i]=0;
        }
        bool bz1=true;
        int ans=0;
        for(int i=n;i>=1;i--){
            if(tg[i]&&bz1){
                bz1=false;
                a[i]=0;
                ans+=a[i];
                continue;
            }
            if(tg[i]&&bz1==false){
                cout<<ans<<endl;
                return;
            }
            ans+=a[i];
        }
        cout<<ans<<endl;
        return;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
