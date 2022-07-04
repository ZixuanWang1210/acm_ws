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
    int n; cin>>n;
    vector<int> v(n+1),rev(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        rev[n-i+1]=v[i];
    }
    int now=0;
    int nowx=0;
    int len=1;
    bool ok=false;
    int ans=0;
    for(int i=2;i<=n;i++){
        if(v[i]<=v[i-1]){
            if(!ok){
                now=i;
                nowx=v[i];
                v[i]=v[i-1]+1;
                ok=true;
                len++;
                ans=max(ans,len);
            }
            else{
                ok=false;
                i=now;
                v[now]=nowx;
                len=1;
                // ans=max(ans,len);
            }
        }
        else len++;
    }

    now=0;
    nowx=0;
    len=0;
    ok=false;
    ans=0;
    for(int i=1;i<=n;i++){
        if(rev[i]<=rev[i-1]){
            if(!ok){
                now=i;
                nowx=rev[i];
                rev[i]=rev[i-1]+1;
                ok=true;
                len++;
                ans=max(ans,len);
            }
            else{
                ok=false;
                i=now;
                rev[now]=nowx;
                len=1;
                ans=max(ans,len);
            }
        }
        else len++;
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
