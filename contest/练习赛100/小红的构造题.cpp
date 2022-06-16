#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

int a[100000000];
int maxn=500000;

void init(){
    a[1]=1;
    for(int i=2;i<=maxn;i++){
        a[i]=a[i-1]+i;
    }
}

void sol(){
    int k; cin>>k;
    for(int i=maxn;i>=1;i--){
        while(k>=a[i]) cout<<'r',k-=a[i];
        cout<<"ed";
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    freopen("out.txt","w",stdout);
    init();
    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
