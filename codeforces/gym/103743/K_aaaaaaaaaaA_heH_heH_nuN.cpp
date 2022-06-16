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

int a[1000];

void init(){
    a[1]=1;
    for(int i=2;i<=50;i++){
        a[i]=(a[i-1]+1)*2-1;
    }
}

void sol(){
    int x; cin>>x;
    cout<<"nunhehhe";
    for(int i=35;i>=1;i--){
        while(x>=a[i]) cout<<'h',x-=a[i];
        cout<<'a';
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    init();
    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
