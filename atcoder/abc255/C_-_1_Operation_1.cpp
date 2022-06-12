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

void sol(){
    int x,a,d,n;
    cin>>x>>a>>d>>n;
    int n1=floor((double)(x-a)/d+1);
    int n2=ceil((double)(x-a)/d+1);
    n1=max(n1,1ll),n2=max(n2,1ll);
    cout<<min(abs(x-(a+(min(n1,n)-1)*d)),abs(x-(a+(min(n2,n)-1)*d)))<<endl;
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
