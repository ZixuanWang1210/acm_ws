#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n;
    cin>>n;
    vector<int> v(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int re=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    for(int i=1;i<=n;i++){
        if(b[i]>v[i]){
            cout<<"NO"<<endl;
            return;
        }

        if(b[i]&&!re) re=max(0ll,v[i]-b[i]);
    }
    if(re==0){
        cout<<"YES"<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=0){
            if(v[i]-b[i]!=re){
                puts("NO");
                return;
            }
        }else{
            if(v[i]-b[i]>re){
                puts("NO");
                return;
            }
        }
    }
    cout<<"YES"<<endl;

}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
