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
    int n,k; cin>>k>>n;
    vector<int> s(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    for(int i=2;i<=n;i++){
        a[i]=s[i]-s[i-1];
    }
    if(n==k){
        a[1]=s[1];
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }
    for(int i=3;i<=n;i++){
        if(a[i]<a[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    int ee=ceil((double)s[1]/(k-n+1));
    if(ee>a[2]){
        cout<<"No"<<endl;
        return;
    }

    cout<<"YES"<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
