#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int ans=0;
    int a[1000]={0};
    int _max=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int re=a[1];
    for(int i=1;i<=n;i++){
        int cnt=0;
        while(a[i+1]<a[i]&&i+1<=n) i++,cnt++;
        ans=max(ans,cnt);
    }
    for(int i=n;i>=1;i--){
        int cnt=0;
        while(a[i]>a[i-1]&&i-1>=1) i--,cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    

    return 0;
}
