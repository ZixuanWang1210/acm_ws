#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
// #define int long long

using namespace std;

const int maxn=5e5+10;
int a[maxn],b[maxn];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    for(int i=1;i<=n;i++){
        if(b[i]>a[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    int re=0;
    for(int i=1;i<=n;i++){
        re=max(re,a[i]-b[i]);
    }

    for(int i=1;i<=n;i++){
        if(b[i]&&a[i]-b[i]!=re){
            cout<<"NO"<<endl;
            return;
        }
        if(b[i]==0&&a[i]-b[i]>re){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
